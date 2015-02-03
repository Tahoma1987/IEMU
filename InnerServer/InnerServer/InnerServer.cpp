////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////


#include "stdafx.h"
#include "defines.h"
#include "structs.h"
#include "common\logger.h"
#include "Settings.h"
#include "InnerServer.h"

#define PACKET_LEN	1024*64


bool SendOK(uint8 id, SOCKET s)
{
	int retVal;
	char packet_buf[3];
	packet_buf[0] = id;
	packet_buf[1] = 0x0a;
	retVal = send(s, packet_buf, 2, NULL);
	if (retVal == SOCKET_ERROR) {
		log::Error(fg, "InnerThread: Disconnect.\n", WSAGetLastError());
		closesocket(s);
//		WinSockThread(NULL);
		return false;
	}
	return true;
}


DWORD WINAPI WinSockThread(LPVOID Param)
{
	bool oneshowmsg = false;
	int serve = 0;
	int retVal;
	bool connected = true;
	int packet_len;
	char packet_buf[PACKET_LEN];
	THREAD_SEND* stc = (THREAD_SEND*)Param;
	stc->id = -1;
	int step = 0;

	while (connected)
	{
		if ((packet_len = recv(stc->socket, packet_buf, PACKET_LEN, 0)) != SOCKET_ERROR)// 0)
		{
			switch (packet_buf[0])
			{
			case 1:
			{
				serve = 1;
				////////////////////////////////////////////////////////////////////////
				/// From login server
				////////////////////////////////////////////////////////////////////////
				switch (packet_buf[1])
				{
				case 0x11:
					log::Info(fg, "InnerThread: [%s] LoginServer connection.\n", inet_ntoa(stc->from));
					if (!SendOK(stc->id, stc->socket))
						return 0;
					break;
				case 0x21:
					packet_buf[0] = 0x22;
					step = 0;
					for (int i = 0; i < 12; i++)
					{
						gs_info[i].cs_ip = cs_info[i].ip;
						gs_info[i].cs_port = cs_info[i].port;
						++step;
					}

					packet_buf[1] = 12;
					step = 2;
					for (int i = 0; i < 12; i++)
					{
						memcpy(packet_buf + step, &gs_info[i], sizeof(GAMESERVER_INFO));
						step += sizeof(GAMESERVER_INFO);
					}
					retVal = send(stc->socket, packet_buf, step, NULL);
					if (retVal == SOCKET_ERROR) {
						log::Error(fg, "InnerThread: Disconnect.\n", WSAGetLastError());
						closesocket(s);
						return 0;
					}
					else
					{
						if (!oneshowmsg)
						{
							log::Info(fg, "InnerThread: [%s] Login Server update information.\n", inet_ntoa(stc->from));
							oneshowmsg = true;
						}
					}
					break;
				}
				break;
			}
			case 2:
			{
				serve = 2;
				////////////////////////////////////////////////////////////////////////
				/// From character server
				////////////////////////////////////////////////////////////////////////
				switch (packet_buf[1])
				{
				case 0x11:
					log::Info(fg, "InnerThread: [%s] Character Server (%d) connection.\n", inet_ntoa(stc->from), packet_buf[2]);
					stc->id = packet_buf[2];
					if (!SendOK(stc->id, stc->socket))
						return 0;
					break;

				case 0x13:
					if (!oneshowmsg)
						log::Info(fg, "InnerThread: [%s] Character Server (%d) send info.\n", inet_ntoa(stc->from), stc->id);
					stc->cs_info[stc->id].id = stc->id;
					memcpy(&stc->cs_info[stc->id], packet_buf + 2, sizeof(CHARACTERSERVER_INFO));
					if (!SendOK(stc->id, stc->socket))
						return 0;
					oneshowmsg = true;
					break;
				default:
					if (stc->id != -1)
						log::Info(fg, "InnerThread: [%s] Character Server (%d) Unknown package.\n", inet_ntoa(stc->from), stc->id);
					else
						log::Info(fg, "InnerThread: [%s] Character Server Unknown package.\n", inet_ntoa(stc->from));
					break;
				}
				break;
			}
			case 3:
			{
				serve = 3;
				////////////////////////////////////////////////////////////////////////
				/// From game server
				////////////////////////////////////////////////////////////////////////
				switch (packet_buf[1])
				{
				case 0x11:
					log::Info(fg, "InnerThread: [%s] Game Server (%d) connection.\n", inet_ntoa(stc->from), packet_buf[2]);
					stc->id = packet_buf[2];
					if (!SendOK(stc->id, stc->socket))
						return 0;
					break;

				case 0x13:
					if (!oneshowmsg)
						log::Info(fg, "InnerThread: [%s] Game Server (%d) send info.\n", inet_ntoa(stc->from), stc->id);
					stc->gs_info[stc->id].id = stc->id;
					memcpy(&stc->gs_info[stc->id], packet_buf + 3, sizeof(GAMESERVER_INFO));
					if (!SendOK(stc->id, stc->socket))
						return 0;
					oneshowmsg = true;
					break;

				default:
					if (stc->id != -1)
						log::Info(fg, "InnerThread: [%s] Game Server (%d) Unknown package.\n", inet_ntoa(stc->from), stc->id);
					else
						log::Info(fg, "InnerThread: [%s] Game Server Unknown package.\n", inet_ntoa(stc->from));
					break;

				}
				break;
			}
			default:
				log::Warn(fg, "InnerThread: [%s] Unknown connection.\n", inet_ntoa(stc->from));
				connected = false;
			}
		}
		else
		{
			int nError = WSAGetLastError();
			if (nError != WSAEWOULDBLOCK && nError != 0)
			{
				switch (serve)
				{
				case 1:
					log::Error(fg, "InnerThread: [%s] Login Server disconnect.\n", inet_ntoa(stc->from));
					break;
				case 2:
					log::Error(fg, "InnerThread: [%s] Character Server disconnect.\n", inet_ntoa(stc->from));
					break;
				case 3:
					log::Error(fg, "InnerThread: [%s] Game Server disconnect.\n", inet_ntoa(stc->from));
					stc->gs_info[stc->id].id = -1;
					break;
				}
				closesocket(stc->socket);
				return 0;
			}
		}

		Sleep(100);
	}
	
	if (stc->socket != NULL)
		closesocket(stc->socket);

	log::Info(fg, "InnerThread: [%s] Disconnect.\n", inet_ntoa(stc->from));

	delete(stc);
	return 0;
	
}


int _tmain(int argc, _TCHAR* argv[])
{
	int err;
	u_long iMode = 1;
	const char on = 1;
	InitializeCriticalSection(&gCS);

	for (int i = 0; i < 32; i++)
	{
		gs_info[i].id = -1;
		cs_info[i].id = -1;
	}

	wVersionRequested = MAKEWORD(2, 2);
	WSAStartup(wVersionRequested, &wsaData);

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	fg = log::Init();
	COLOR_GL
	log::Notify(fg, "\n");
	log::Notify(fg, "#################################\n");
	log::Notify(fg, "# Inner Server v0.51            #\n");
	log::Notify(fg, "# Authors: Tahoma               #\n");
	log::Notify(fg, "#################################\n\n");

	///////////////////////////////////////////////////////////////
	// Загрузка конфигурации
	///////////////////////////////////////////////////////////////
	COLOR_RGBL
	log::Notify(fg, "Load Settings... \t");

	if (!LoadSettings(&settings))
	{
		COLOR_RL
		log::Notify(fg, "Fail\n");
		return -1;
	}

	COLOR_GL
	log::Notify(fg, "Succesful\n");
	//--------------------------------------------------------------------------------------------------------------------------

	log::Notify(fg, "\nServer is running. (%s:%d)\n", ip, port);
	COLOR_RGBL
	//--------------------------------------------------------------------------------------------------------------------------
	Sleep(500);

	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
	err = ioctlsocket(s, FIONBIO, &iMode);

	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(ip);

	err = bind(s, (LPSOCKADDR)&sin, sizeof(sin));
	err = listen(s, SOMAXCONN);
	
	int fromlen;
	while (true)
	{
		fromlen = sizeof(from);
		sock_accept = accept(s, (struct sockaddr*)&from, &fromlen);
		if (sock_accept != INVALID_SOCKET)
		{
			THREAD_SEND* send = new THREAD_SEND;
			send->fg = fg;
			send->socket = sock_accept;
			send->from = from.sin_addr;
			send->gs_info = gs_info;
			send->cs_info = cs_info;
			send->hpthr = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)WinSockThread, send, NULL, NULL);
		}
		Sleep(100);
	}
	WSACleanup();

	settings.Destroy();
	return 0;
}


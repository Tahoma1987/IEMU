////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#include "stdafx.h"
#include "defines.h"
#include "common\database.h"
#include "structs.h"
#include "common\logger.h"
#include "Settings.h"
#include "LoginServer.h"

#include "network\packet.h"
#include "network\opcodes.h"

//====================================================================================
// Player connections
//
DWORD WINAPI WinSockThread(LPVOID Param)
{
	int tick = 0;
	EnterCriticalSection(&gCS);
	THREAD_STRUCT* th_struct = (THREAD_STRUCT*)Param;
	PACKET* pck = new PACKET(th_struct);
	memset(pck->sockstruct->account_name, 0, sizeof(pck->sockstruct->account_name));
	LeaveCriticalSection(&gCS);

	while (pck->isconnected)
	{
		EnterCriticalSection(&gCS);
		if (tick > 50)
		{
			tick = 0;
			SM_UPDATESERVERINFO(pck);
		}

		if (pck->PackRecv())
		{
			/*// DEBUG
			char bindbg[2];
			memset(bindbg, 0, 2);

			char* fordebug = pck->GetPacketPointer();
			log::Debug(fg, "C->S: op[%04x][%02x] ", pck->opcode, pck->real_packet_size);
			for (uint16 i = 0; i < (uint16)pck->packet_len; i++)
			{
				if ((uint8)fordebug[i] > 0x20 && (uint8)fordebug[i] <= 'z')
				{
					bindbg[0] = (uint8)fordebug[i];
					log::Notify(fg, bindbg);
				}
				else
					log::Notify(fg, ".");
			}
			log::Notify(fg, "\n");

			log::Debug(fg, "C->S: op[%04x][%02x] ", pck->opcode, pck->real_packet_size);
			for (uint16 i = 0; i < (uint16)pck->packet_len; i++)
				log::Notify(fg, "%02x", (uint8)fordebug[i]);

			log::Notify(fg, "\n");
			// --DEBUG*/

			opcodes(pck);
		}
		LeaveCriticalSection(&gCS);
		Sleep(100);
		++tick;
	}
	
	if (strlen(pck->sockstruct->account_name) != 0)
		log::Info(fg, "Disconnect account: %s\n", pck->sockstruct->account_name);

	delete (pck);
	if (th_struct->socket != NULL)
		closesocket(th_struct->socket);

	delete(th_struct);
	return 0;
}

DWORD WINAPI InnerThread(LPVOID Param)
{
	int tmp = 0;
	int retVal = 0;
	char packet[PACKET_LEN];
	time_t rawTime;
	LPHOSTENT hostEnt;

	if (lsinnerSock != NULL)
	{
		closesocket(lsinnerSock);
		lsinnerSock = NULL;
		Sleep(5000);
	}

	hostEnt = gethostbyname(inner_ip);
	lsinnerSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (lsinnerSock == SOCKET_ERROR)
	{
		log::Error(fg, "InnerThread: Unable to create socket.\n");
		InnerThread(NULL);
		return 0;
	}

	SOCKADDR_IN serverInfo;
	serverInfo.sin_family = PF_INET;
	serverInfo.sin_addr = *((LPIN_ADDR)*hostEnt->h_addr_list);
	serverInfo.sin_port = htons(inner_port);
	retVal = connect(lsinnerSock, (LPSOCKADDR)&serverInfo, sizeof(serverInfo));
	if (retVal == SOCKET_ERROR)
	{
		log::Error(fg, "InnerThread: Unable to connect\n");
		closesocket(lsinnerSock);
		InnerThread(NULL);
		return 0;
	}

	SetConsoleTextAttribute(hConsole, (WORD)FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	log::Info(fg, "InnerThread: Connected succesful.\n");

	int status = 0;
	int step = 1;

	while (true)
	{
		if (lsinnerSock == NULL)
			break;
		switch (status)
		{
		case 0:
		{
			packet[0] = 1;
			packet[1] = 0x11;
			retVal = send(lsinnerSock, packet, 2, 0);
			if (retVal == SOCKET_ERROR) {
				log::Error(fg, "InnerThread: Disconnect.\n", WSAGetLastError());
				closesocket(lsinnerSock);
				InnerThread(NULL);
				return 0;
			}
			else
				log::Info(fg, "InnerThread: Connected.\n");
			status = 1;
		}
			break;

		case 1:
		{
			packet[0] = 1;
			packet[1] = 0x21;
			retVal = send(lsinnerSock, packet, 2, 0);
			if (retVal == SOCKET_ERROR) {
				log::Error(fg, "InnerThread: Disconnect.\n", WSAGetLastError());
				closesocket(lsinnerSock);
				InnerThread(NULL);
				return 0;
			}
			status = 2;
		}
			break;

		case 2:
		{
			retVal = recv(lsinnerSock, packet, PACKET_LEN, NULL);
			if (retVal == SOCKET_ERROR) {
					log::Error(fg, "InnerThread: Disconnect.\n", WSAGetLastError());
					closesocket(lsinnerSock);
					InnerThread(NULL);
					return 0;
				}
			else
			{
				if (packet[0] == 0x22)
				{
					step = 2;
/*					for (int i = 0; i < packet[1]; i++)
					{
						memcpy(&gameservers_info[packet[step]], &packet[step], sizeof(GAMESERVERS));
						step += sizeof(GAMESERVERS);
					}*/

					for (int i = 0; i < 12; i++)
					{
						if (packet[step] == -1)
						{
							gameservers_info[i].id = -1;
						}
						else
						{
							memcpy(&gameservers_info[i], &packet[step], sizeof(GAMESERVERS));
						}
						step += sizeof(GAMESERVERS);
					}
				}
				status = 1;
			}
		}
			break;
		}
		Sleep(5000);
	}

	return 0;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int err;
	u_long iMode = 1;
	const char on = 1;
	sockaddr_in	from;
	SOCKET s;
	SOCKET sock_accept;
	struct sockaddr_in sin;
	lsinnerSock = NULL;

	wVersionRequested = MAKEWORD(2, 2);
	WSAStartup(wVersionRequested, &wsaData);

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COLOR_GL
	fg = log::Init();

	log::Notify(fg, "\n");
	log::Notify(fg, "#################################\n");
	log::Notify(fg, "# Login Server v0.93            #\n");
	log::Notify(fg, "# Client version: 1.5.73        #\n");
	log::Notify(fg, "# Client time: 2015-02-02 17:26 #\n");
	log::Notify(fg, "#################################\n\n");

	///////////////////////////////////////////////////////////////
	// Load Settings
	///////////////////////////////////////////////////////////////
	COLOR_RGBL
	log::Notify(fg, "Load Settings... \t\t");
	setlocale(LC_ALL, "");
	Configuration* cfg = settings.Init();
	if (cfg == NULL)
	{
		COLOR_RL
		log::Notify(fg, "Fail\n");
		return -1;
	}

	db_host = cfg->lookupString("", "db_host", "127.0.0.1");
	db_user = cfg->lookupString("", "db_user", "root");
	db_pass = cfg->lookupString("", "db_pass", "password");
	db_name = cfg->lookupString("", "db_name", "ica_ls");
	launcher_ip = cfg->lookupString("", "ip", "127.0.0.1");			// ip address loginserver
	launcher_port = cfg->lookupInt("", "port", 5694);				// port loginserver
	inner_ip = cfg->lookupString("", "inner_ip", "127.0.0.1");		// ip address inner
	inner_port = cfg->lookupInt("", "inner_port", 5600);			// inner port

	COLOR_GL
	log::Notify(fg, "Succesful\n");
	//-------------------------------------------------------------


	COLOR_RGBL
	log::Notify(fg, "Connect to Mysql... \t\t");
	mysql = new DATABASE(fg, (char*)db_host, (char*)db_user, (char*)db_pass, (char*)db_name);
	if (mysql->IsError())
	{
		COLOR_RL
		log::Notify(fg, "Fail\n");
		return -1;
	}

	COLOR_GL
	log::Notify(fg, "Succesful\n");
	log::Notify(fg, "\nServer is running. (%s:%d)\n", launcher_ip, launcher_port);
	COLOR_RGBL
	Sleep(500);

	// inner server
	HANDLE hthInner = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)InnerThread, NULL, NULL, NULL);

	InitializeCriticalSection(&gCS);

	s = socket(AF_INET, SOCK_STREAM, NULL);	
	setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
	err = ioctlsocket(s, FIONBIO, &iMode);

	sin.sin_family = AF_INET;
	sin.sin_port = htons(launcher_port);
	sin.sin_addr.s_addr = inet_addr(launcher_ip);

	err = bind(s, (LPSOCKADDR)&sin, sizeof(sin));
	err = listen(s, SOMAXCONN);

	int fromlen;

	while (true)
	{	

		fromlen = sizeof(from);
		sock_accept = accept(s, (struct sockaddr*)&from, &fromlen);
		if (sock_accept != INVALID_SOCKET)
		{
			THREAD_STRUCT* th_struct = new THREAD_STRUCT;
			th_struct->socket = sock_accept;
			th_struct->fg = fg;
			th_struct->mysql = mysql;
			th_struct->gameservers_info = gameservers_info;
			th_struct->hpthr = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)WinSockThread, th_struct, NULL, &th_struct->thrSocketRead);
		}

		Sleep(100);
	}
	WSACleanup();

	return 0;
}


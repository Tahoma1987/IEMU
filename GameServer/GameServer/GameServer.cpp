////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#include "stdafx.h"
#include "defines.h"
#include "game_structs.h"
#include "common/database.h"
#include "structs.h"
#include "common/logger.h"
#include "Settings.h"
#include "GameServer.h"

//================================================================================
// Нить обрабтки пакетов принятых от клиента
//
DWORD WINAPI WinSockThread(LPVOID Param)
{
	THREAD_SEND* send = (THREAD_SEND*)Param;
	InitializeCriticalSection(&send->player->gCSp);
	EnterCriticalSection(&send->player->gCSp);

	send->player->pck = new PACKET(send->player->socket, &send->player->character, (DATABASE*)send->sys.mysql, send->sys.fg, &send->player->ping_time);
	PACKET* pck = (PACKET*)send->player->pck;
	mychar->id = 0;
	mychar->target_id = -1;
	mychar->status = STATUS_NONE;
	mychar->action = ACTION_NONE;
	mychar->ingame = false;
	mychar->items_in_inventory = 0;
	mychar->fly = false;
	mychar->halt = true;
	LeaveCriticalSection(&send->player->gCSp);
	

	while (pck->isconndected)
	{
		EnterCriticalSection(&send->player->gCSp);
		
		if (mychar->status == STATUS_NONE)
		{
			if (!pck)
			{
				LeaveCriticalSection(&send->player->gCSp);
				break;
			}
			if (pck->PackRecv())
			{
				do
				{
					if ((uint16)pck->packet_len == 0)
					{
						pck->isconndected = false;
						break;
					}

					/*// DEBUG
					char bindbg[2];
					memset(bindbg, 0, 2);

					char* fordebug = pck->GetPacketPointer();
					lg::Debug(fg, "C->S: op[%04x][%02x] ", pck->opcode, pck->real_packet_size);
					for (uint16 i = 0; i < (uint16)pck->packet_len; i++)
					{
						if ((uint8)fordebug[i] > 0x20 && (uint8)fordebug[i] <= 'z')
						{
							bindbg[0] = (uint8)fordebug[i];
							lg::Notify(fg, bindbg);
						}
						else
							lg::Notify(fg, ".");
					}
					lg::Notify(fg, "\n");

					lg::Debug(fg, "C->S: op[%04x][%02x] ", pck->opcode, pck->real_packet_size);
					for (uint16 i = 0; i < (uint16)pck->packet_len; i++)
						lg::Notify(fg, "%02x", (uint8)fordebug[i]);

					lg::Notify(fg, "\n");
					// --DEBUG*/

					OPCODES::opcodes(pck, fg);
				} while (pck->NextPacket());
			}
		}
		LeaveCriticalSection(&send->player->gCSp);
		Sleep(100);
	}

	while (mychar->status != STATUS_NONE)
	{
		send->player->status = false;
		Sleep(100);
	}


	lg::Info(fg, "GSNetwork [%s]: Disconnect character: %s\n", inet_ntoa(send->player->from), pck->me->tcharname);
	
	if (send->player->socket != NULL)
		closesocket(send->player->socket);

	delete (pck);
	delete (send);
	return 0;
	
}

//================================================================================
// Нить посылающая пинги до клиента. Если молчит, разрываем соединение
//
DWORD WINAPI WinSockPing(LPVOID Param)
{
	ALL_PLAYERS* players = (ALL_PLAYERS*)Param;
	while (true)
	{
		for (int i = 0; i < max_players; i++)
		{
			if (players[i].status == true && players[i].socket != NULL)
			{
				EnterCriticalSection(&players[i].gCSp);

				PACKET* pck = (PACKET*)players[i].pck;
				OPCODES::SM_PONG(pck);
				time_t rawTime;
				time(&rawTime);
				int time = rawTime - players[i].ping_time;
				if (time > 0 && time > max_time_for_disconnect)
				{
					pck->Disconnect();
					lg::Warn(fg, "PingThread: Сlient does not respond. Character: %s\n", pck->me->charname);
				}	
				
				LeaveCriticalSection(&players[i].gCSp);
			}
		}
		Sleep(5000);
	}
}

//================================================================================
// Нить для обработки действий всех субъектов на сервере
//
DWORD WINAPI ActionControllerThread(LPVOID Param)
{
	ACTIONCONTROLLER* action_controller = (ACTIONCONTROLLER*)Param;

	while (true)
	{
		action_controller->Frame();
		Sleep(10);
	}
	return 0;
}

//================================================================================
// Основная нить сервера
//
DWORD WINAPI AIMainThread(LPVOID Param)
{
	AI* ai = (AI*)Param;

	while (true)
	{
		ai->Frame();
		Sleep(10);
	}
	
	return 0;

}

DWORD WINAPI InnerThread(LPVOID Param)
{
	int tmp = 0;
	int retVal = 0;
	char packet[256];
	time_t rawTime;
	LPHOSTENT hostEnt;
	GAMESERVER_INFO	g_info;

	memset(g_info.name, 0, 42);	
	strcpy(g_info.name, name_server);

	hostEnt = gethostbyname(inner_ls_ip);
	SOCKET lsSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (lsSock == SOCKET_ERROR)
	{
		lg::Error(fg, "InnerThread: Unable to create socket.\n");
		return false;
	}

	SOCKADDR_IN serverInfo;
	serverInfo.sin_family = PF_INET;
	serverInfo.sin_addr = *((LPIN_ADDR)*hostEnt->h_addr_list);
	serverInfo.sin_port = htons(inner_ls_port);
	retVal = connect(lsSock, (LPSOCKADDR)&serverInfo, sizeof(serverInfo));
	if (retVal == SOCKET_ERROR)
	{
		lg::Error(fg, "InnerThread: Unable to connect\n");
		closesocket(lsSock);
		Sleep(5000);
		InnerThread(NULL);
		return false;
	}

	SetConsoleTextAttribute(hConsole, (WORD)FOREGROUND_GREEN | FOREGROUND_INTENSITY);
//	lg::Info(fg, "InnerThread: Connected succesful.\n");

	uint16 opcode = 1;

	int status = 0;

	while (true)
	{
		switch (status)
		{
		case 0:
			packet[0] = 3;
			packet[1] = 0x11;
			packet[2] = id_server;
			retVal = send(lsSock, packet, 3, 0);
			if (retVal == SOCKET_ERROR) {
				lg::Error(fg, "InnerThread: Disconnect.\n", WSAGetLastError());
				closesocket(lsSock);
				Sleep(5000);
				InnerThread(NULL);
				return 0;
			}
			else
			{
				lg::Info(fg, "InnerThread: Connected succesful.\n");
			}
			status = 1;
			break;

		case 1:
			time(&rawTime);
			tmp = 0;
			g_info.id = (uint8)id_server;
			for (int i = 0; i < max_players; i++)
			{
				if (allplayers[i].status)
					++tmp;
			}
			g_info.players_connected = tmp;
			g_info.players_max = max_players;
			g_info.status = technical_works;
			g_info.timeupdate = rawTime;

			packet[0] = 3;
			packet[1] = 0x13;
			memcpy(&packet[3], &g_info, sizeof(GAMESERVER_INFO));

			retVal = send(lsSock, packet, sizeof(GAMESERVER_INFO) + 3, 0);
			if (retVal == SOCKET_ERROR) {
				lg::Error(fg, "InnerThread: Disconnect.\n", WSAGetLastError());
				closesocket(lsSock);
				Sleep(5000);
				InnerThread(NULL);
				return 0;
			}
			Sleep(refresh_server_info);
			break;
		}
		Sleep(5000);
	}
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
/*	int st = 0x30000000;
	float ft;
	ft = *(float*)&st;
	ft = 1;
	st = *(int*)&ft;*/

	int err;
	u_long iMode = 1;
	const char on = 1;
	InitializeCriticalSection(&gCS);

	wVersionRequested = MAKEWORD(2, 2);
	WSAStartup(wVersionRequested, &wsaData);

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	fg = lg::Init();
	COLOR_GL
	lg::Notify(fg, "\n");
	lg::Notify(fg, "#################################\n");
	lg::Notify(fg, "# Game Server v0.05             #\n");
	lg::Notify(fg, "# Client version: 1.5.73        #\n");
	lg::Notify(fg, "# Client time: 2015-02-02 17:26 #\n");
	lg::Notify(fg, "#################################\n\n");
	
	///////////////////////////////////////////////////////////////
	// Загрузка конфигурации
	///////////////////////////////////////////////////////////////
	COLOR_RGBL
	lg::Notify(fg, "Load Settings... \t\t");

	if (!LoadSettings(&settings))
	{
		COLOR_RL
		lg::Notify(fg, "Fail\n");
		return -1;
	}

	COLOR_GL
	lg::Notify(fg, "Succesful\n");
//--------------------------------------------------------------------------------------------------------------------------
	COLOR_RGBL
	lg::Notify(fg, "Connect to Mysql... \t\t");
	mysql = new DATABASE(fg, (char*)db_host, (char*)db_user, (char*)db_pass, (char*)db_name);
	mysql2 = new DATABASE(fg, (char*)db_host, (char*)db_user, (char*)db_pass, (char*)db_name);
	if (mysql->IsError())
		return -1;

	COLOR_GL
	lg::Notify(fg, "Succesful\n");

	COLOR_RGBL
		lg::Notify(fg, "ID server... \t\t\t");
	if (id_server > 12)
	{
		COLOR_RL
		lg::Notify(fg, "Fail\n");
		return -1;
	}
	else
	{
		COLOR_GL
		lg::Notify(fg, "%d\n", id_server);
	}

	COLOR_RGBL
	lg::Notify(fg, "Max players... \t\t\t");
	COLOR_GL
	lg::Notify(fg, "%d\n", max_players);

	allplayers = new ALL_PLAYERS[max_players];
	for (int i = 0; i < max_players; i++)
	{
		allplayers[i].status = false;
		allplayers[i].socket = NULL;
		allplayers[i].pck = NULL;
	}

	///////////////////////////////////////////////////////////////
	// Загрузка информации для сервера
	///////////////////////////////////////////////////////////////
	int nummobsload = 0;
	int nummobs = mysql->GetNumMobs();
	COLOR_RGBL;
	lg::Notify(fg, "Spawn data... \t\t\t");
	if (nummobs == 0)
	{
		COLOR_RL;
		lg::Notify(fg, "Empty\n");
	}
	else
	{
		COLOR_GL;
		mobs = new MOB[nummobs];
		nummobsload = mysql->GetMobs(mobs);
		for (int i = 0; i < nummobsload; i++)
		{
			memset(mobs[i].accounts_show, 0, max_players);
//			mobs[i].account_show = malloc(max_players + 1);
//			memset(mobs[i].account_show, 0, max_players + 1);
		}
		lg::Notify(fg, "%d\n", nummobsload);
	}

	COLOR_RGBL;
	int	all_num_skills = 0;
	lg::Notify(fg, "Skills data...\t\t\t");

	COLOR_GL;
	lg::Notify(fg, "%d\n", all_num_skills);


//--------------------------------------------------------------------------------------------------------------------------
	// Запуск основных нитей сервера
	server = new AI(fg, mysql, allplayers, mobs, max_players, nummobsload);
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)AIMainThread, server, NULL, NULL);
	actioncontroller = new ACTIONCONTROLLER(fg, mysql2, allplayers, mobs, max_players, nummobsload);
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ActionControllerThread, actioncontroller, NULL, NULL);
//--------------------------------------------------------------------------------------------------------------------------
	// Запуск слежения за состояниями соединений игроков
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)WinSockPing, allplayers, NULL, NULL);
//--------------------------------------------------------------------------------------------------------------------------
	COLOR_GL
	lg::Notify(fg, "\nServer is running. (%s:%d)\n", gameserver_ip, gameserver_port);
	COLOR_RGBL
//--------------------------------------------------------------------------------------------------------------------------

	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
	err = ioctlsocket(s, FIONBIO, &iMode);

	si.sin_family = AF_INET;
	si.sin_port = htons(gameserver_port);
	si.sin_addr.s_addr = inet_addr(gameserver_ip);

	err = bind(s, (LPSOCKADDR)&si, sizeof(si));
	err = listen(s, SOMAXCONN);
	
	// Запуск внутреннего обмена
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)InnerThread, NULL, NULL, NULL);

	int fromlen;
	while (true)
	{
		fromlen = sizeof(from);
		sock_accept = accept(s, (struct sockaddr*)&from, &fromlen);
		if (sock_accept != INVALID_SOCKET)
			for (int i = 0; i < max_players; i++)
				if (allplayers[i].status == false)
				{
					THREAD_SEND* send = new THREAD_SEND;
					send->sys.fg = fg;
					send->sys.mysql = mysql;
					send->player = &allplayers[i];
					send->player->status = true;
					send->player->from = from.sin_addr;
					send->player->socket = sock_accept;
					send->player->hpthr = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)WinSockThread, send, NULL, NULL);
					break;
				}
		Sleep(100);
	}
	WSACleanup();

	settings.Destroy();
	delete(allplayers);
	return 0;
}


////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _LAUNCHER_SERVER_H_
#define _LAUNCHER_SERVER_H_

#include <config4cpp\Configuration.h>
#include "network/packet.h"
#include "network/opcodes.h"

using namespace OPCODES;

#include "AI\ai.h"
#include "AI\ActionController.h"

using namespace config4cpp;

// Sockets
WORD				wVersionRequested;
WSADATA				wsaData;
SOCKET				s;
SOCKET				sock_accept;
sockaddr_in			from;
struct				sockaddr_in si;
HANDLE				hpthr;
SETTINGS			settings;
CRITICAL_SECTION	gCS;
HANDLE				hConsole;

FILE*				fg;				// Хэндл файла для логера

DATABASE*			mysql;
DATABASE*			mysql2;
ALL_PLAYERS*		allplayers;
MOB*				mobs;
AI*					server;
ACTIONCONTROLLER*	actioncontroller;
SKILLS*				skill;


#endif _LAUNCHER_SERVER_H_
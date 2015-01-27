////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _LAUNCHER_SERVER_H_
#define _LAUNCHER_SERVER_H_

#include <config4cpp\Configuration.h>

using namespace config4cpp;

// Sockets
WORD				wVersionRequested;
WSADATA				wsaData;
SOCKET				s;
SOCKET				sock_accept;
sockaddr_in			from;
struct				sockaddr_in sin;
HANDLE				hpthr;
SETTINGS			settings;
CRITICAL_SECTION	gCS;
HANDLE				hConsole;

FILE*				fg;				// Хэндл файла для логера

GAMESERVER_INFO		gs_info[32];
CHARACTERSERVER_INFO cs_info[32];


#endif _LAUNCHER_SERVER_H_
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
HANDLE				hpthr;
SETTINGS			settings;
CRITICAL_SECTION	gCS;
GAMESERVERS			gameservers_info[12];
HANDLE				hConsole;
SOCKET				lsinnerSock;

FILE*				fg;				// хэндл для логирования

DATABASE*			mysql;

#endif _LAUNCHER_SERVER_H_
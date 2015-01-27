////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _LAUNCHER_SERVER_H_
#define _LAUNCHER_SERVER_H_

#include <config4cpp\Configuration.h>
#include <time.h>
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
SOCKET				csInnectSock;

FILE*				fg;				// ¬ç¬ï¬ß¬Õ¬Ý ¬Õ¬Ý¬ñ ¬Ý¬à¬Ô¬Ö¬â¬Ñ

DATABASE*			mysql;			// ¬Ü¬Ý¬Ñ¬ã¬ã ¬Õ¬Ý¬ñ ¬â¬Ñ¬Ò¬à¬ä¬í ¬ã ¬¢¬¥

#endif _LAUNCHER_SERVER_H_
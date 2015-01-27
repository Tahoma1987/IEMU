////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _STRUCTS_H_
#define _STRUCTS_H_

#include "game_structs.h"

typedef struct SYSTEM_STRUCT
{
	FILE*					fg;				/* handle file log */
	void*					mysql;			/* mysql class */
} SYSTEM_STRUCT;

typedef struct ALL_PLAYERS
{
	bool					status;
	SOCKET					socket;
	void*					pck;
	in_addr					from;
	HANDLE					hpthr;			/* Thread handle */
	DWORD					thrSocketRead;
	CHARACTER				character;
	int						ping_time;
	CRITICAL_SECTION		gCSp;
}ALL_PLAYERS;

typedef struct THREAD_SEND
{
	SYSTEM_STRUCT			sys;
	ALL_PLAYERS*			player;
	MOB						mobs;
}THERAD_SEND;

#pragma pack(1)
struct GAMESERVER_INFO
{
	int8	id;
	char	name[42];
	int		players_connected;
	int		players_max;
	time_t	timeupdate;
	int		cs_ip;
	int		cs_port;
	bool	status;
};
#pragma pack()

#endif _STRUCTS_H_




////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _STRUCTS_H_
#define _STRUCTS_H_

#include "common\database.h"

enum LOAD_SERVER
{
	EASY,
	MEDIUM,
	HIGH
};

#pragma pack(1)
struct GAMESERVERS
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

typedef struct THREAD_STRUCT
{
	HANDLE			hpthr;			/* Thread handle */
	SOCKET			socket;			/* Socket */
	DWORD			thrSocketRead;
	FILE*			fg;				/* handle for logger */
	DATABASE*		mysql;			
	int				account_id;		/* ID account */
	char			account_name[32];
	bool			send_serverlist;
	GAMESERVERS*	gameservers_info;

} THREAD_STRUCT;




#endif _STRUCTS_H_




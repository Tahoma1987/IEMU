////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _STRUCTS_H_
#define _STRUCTS_H_
#include "game_structs.h"

enum {
	STATUS_NONE,
	STATUS_STARTGAME,
	STATUS_DELETE_CHARACTER
};

#pragma pack(1)
struct CHARACTERSERVER_INFO
{
	uint8	id;
	int		ip;
	int		port;
};
#pragma pack()

typedef struct THREAD_STRUCT
{
	HANDLE			hpthr;			/* Thread handle */
	SOCKET			socket;			/* Socket */
	DWORD			thrSocketRead;
	in_addr			from;
	FILE*			fg;
	void*			mysql;
	uint16			account_id;
	CHARACTER*		character;
	char			pin_code[5];
	int				pin_erros;
	int				status;	

} THREAD_STRUCT;

#endif _STRUCTS_H_




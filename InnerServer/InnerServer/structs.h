////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _STRUCTS_H_
#define _STRUCTS_H_



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

struct CHARACTERSERVER_INFO
{
	uint8	id;
	int		ip;
	int		port;
};
#pragma pack()

typedef struct THREAD_SEND
{
	uint8					id;
	FILE*					fg;
	SOCKET					socket;
	in_addr					from;
	HANDLE					hpthr;
	GAMESERVER_INFO*		gs_info;
	CHARACTERSERVER_INFO*	cs_info;
}THERAD_SEND;

#endif _STRUCTS_H_




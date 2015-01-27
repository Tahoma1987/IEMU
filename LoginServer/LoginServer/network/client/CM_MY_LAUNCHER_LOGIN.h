////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _CM_MY_LAUNCHER_LOGIN_H_
#define _CM_MY_LAUNCHER_LOGIN_H_

#include <time.h>

void CM_MY_LAUNCHER_LOGIN(PACKET* pck)
{
	int rnd;
	uint8 oric;
	time_t tms;
	int n = 0;
	char recv[256];
	char hash[256];
	char times[16];

	struct sockaddr_in from;
	int len = sizeof(from);
	getpeername(pck->sockstruct->socket, (struct sockaddr *)&from, &len);

	memset(recv, 0, sizeof(recv));
	memset(hash, 0, sizeof(hash));
	srand(GetTickCount());

	pck->readTstr(recv);

	for (int i = 0; i < 32; i++)
	{
		oric = 0x41;
		rnd = rand();
		if (rnd % 2)
			oric += 0x20;

		rnd = (rand() % 24) | oric;
		rnd = rnd & 0xff;
		memset(hash + n, rnd, 1);
		++n;
	}

	time(&tms);
	tm* timeinfo = localtime(&tms);
	sprintf(times, "%d%02i%02i%02i%02i%02i", timeinfo->tm_year + 1900,
											 timeinfo->tm_mon + 1,
											 timeinfo->tm_mday,
											 timeinfo->tm_hour,
											 timeinfo->tm_min,
											 timeinfo->tm_sec);
	memcpy(hash, times, strlen(times));


	if (!(pck->sockstruct->mysql->CheckAccountName(recv, hash)))
	{	
		log::Error(fg, "LSNetwork [%s]: Hash fail: %s\n", inet_ntoa(from.sin_addr), hash);
		memset(hash, 0, sizeof(hash));
	}
	else
		log::Info(fg, "LSNetwork [%s]: Hash: %s\n", inet_ntoa(from.sin_addr), hash);

	SM_MY_LAUNCHER_LOGIN(pck, hash);
}

#endif _CM_MY_LAUNCHER_LOGIN_H_




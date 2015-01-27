////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_PING_H_
#define _CM_PING_H_

inline void CM_PING(PACKET* pck)
{
	time_t rawTime;
	time(&rawTime);
	pck->pingtime[0] = (int) rawTime;
	int16 unk2 = pck->readW();
	SM_PONG(pck);
}

/*
0700 6501
00af00
*/

#endif
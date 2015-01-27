////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_DISCONNECT_H_
#define _CM_DISCONNECT_H_

inline void CM_DISCONNECT(PACKET* pck)
{
	int8 unk2 = pck->readB();		// 1 - change char
	SM_DISCONNECT(pck);	
}

/*
0EFA
0125
B0
*/

#endif
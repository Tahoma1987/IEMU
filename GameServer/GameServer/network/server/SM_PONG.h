////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_PONG_H_
#define _SM_PONG_H_

inline void SM_PONG(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeB(0);
	pck->PackSend(OPCODE_SM_PONG);
}
/*
0700 6501 
00 0000
*/
#endif


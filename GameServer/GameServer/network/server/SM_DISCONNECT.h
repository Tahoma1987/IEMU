////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_DISCONNECT_H_
#define _SM_DISCONNECT_H_

inline void SM_DISCONNECT(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_DISCONNECT);
}
/*
0e00
0efb
0000
00000000
01000000
*/
#endif




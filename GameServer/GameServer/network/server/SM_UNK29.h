////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK29_H_
#define _SM_UNK29_H_

inline void SM_UNK29(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->writeD(0x00000e10);
	pck->PackSend(OPCODE_SM_UNK29);
}

/*
3F03 0000
E2000000
100E0000               ?...........
*/

#endif


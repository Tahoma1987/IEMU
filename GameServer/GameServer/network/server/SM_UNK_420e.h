////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_420e_H_
#define _SM_UNK_420e_H_

inline void SM_UNK_420e(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_UNK_420e);
}
/*
0E42 0000 00000000 00000000               .@..........
*/
#endif


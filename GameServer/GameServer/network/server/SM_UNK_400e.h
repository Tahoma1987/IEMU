////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_400e_H_
#define _SM_UNK_400e_H_

inline void SM_UNK_400e(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_UNK_400e);
}
/*
0E40 0000 00000000 00000000               .@..........
*/
#endif


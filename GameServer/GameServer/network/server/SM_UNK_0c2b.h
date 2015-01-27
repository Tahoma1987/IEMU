////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_0c2b_H_
#define _SM_UNK_0c2b_H_

inline void SM_UNK_0c2b(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(3);
	pck->writeD(0xffff);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(0xff);
	pck->PackSend(OPCODE_SM_UNK_0c2b);
}

/*
2B0C 0000
03000000
FFFF0000
00000000
00000000
00000000
FF000000
*/

#endif


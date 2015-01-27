////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_9813_H_
#define _SM_UNK_9813_H_

inline void SM_UNK_9813(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeW(5);
	pck->writeD(0);
	pck->writeD(1);
	pck->writeD(2);
	pck->writeD(3);
	pck->writeD(9);
	pck->PackSend(OPCODE_SM_UNK_9813);
}

/*
1398 0000
0500
00000000
01000000
02000000
03000000
09000000                     ..........
*/

#endif


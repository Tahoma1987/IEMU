////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_9c13_H_
#define _SM_UNK_9c13_H_

inline void SM_UNK_9c13(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(3); // for?
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(1);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(9);
	pck->writeD(0);
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_UNK_9c13);
}

/*
139C 0000
03000000 
00000000
00000000
00000000
01000000
00000000
00000000
09000000
00000000
00000000               ............
*/

#endif


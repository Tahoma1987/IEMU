////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_9e13_H_
#define _SM_UNK_9e13_H_

inline void SM_UNK_9e13(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(2);
	pck->writeD(4);
	pck->writeD(1);
	pck->writeD(0);
	pck->writeD(0x6952009);
	pck->writeD(1);
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_UNK_9e13);
}

/*
139E 0000
02000000
04000000
01000000
00000000
09005269
01000000
00000000
*/

#endif


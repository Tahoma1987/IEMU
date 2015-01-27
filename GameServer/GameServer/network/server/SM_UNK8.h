////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK8_H_
#define _SM_UNK8_H_

inline void SM_UNK8(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->writeD(7);
	pck->writeD(7);
	pck->writeD(0);
	pck->writeD(1);
	pck->writeD(2);
	pck->writeD(3);
	pck->writeD(4);
	pck->writeD(5);
	pck->PackSend(OPCODE_SM_UNK8);


}

/*
0E47
0000
00000000
07000000
00000000
01000000
02000000
03000000
04000000
05000000
07000000

*/

#endif


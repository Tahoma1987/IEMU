////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_9713_H_
#define _SM_UNK_9713_H_

inline void SM_UNK_9713(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(5);
	pck->writeD(0);
	pck->writeD(14);
	pck->writeD(1);
	pck->writeD(14);
	pck->writeD(2);
	pck->writeD(0x1e);
	pck->writeD(3);
	pck->writeD(5);
	pck->writeD(9);
	pck->writeD(14);
	pck->PackSend(OPCODE_SM_UNK_9713);
}

/*
1397 0000
05000000
00000000
0F000000   ................
01000000
0F000000
02000000
1E000000   ................
03000000
05000000
09000000
0F000000   ................
*/

#endif


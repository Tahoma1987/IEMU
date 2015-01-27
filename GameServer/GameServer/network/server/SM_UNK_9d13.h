////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_9d13_H_
#define _SM_UNK_9d13_H_

inline void SM_UNK_9d13(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0x311feb05);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(1);
	pck->writeD(0);
	pck->writeD(2);
	pck->writeD(0);
	pck->writeD(3);
	pck->writeD(0);
	pck->writeD(9);
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_UNK_9d13);
}

/*
139D 0000
05EB1F31
00000000
00000000
01000000
00000000
02000000
00000000
03000000
00000000
09000000
00000000   ................
*/

#endif


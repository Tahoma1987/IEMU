////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK27_H_
#define _SM_UNK27_H_

inline void SM_UNK27(PACKET* pck, int unk)
{
	// באפû
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->writeD(pck->me->id);
	pck->writeD(pck->me->id);
	pck->writeD(0xbb0e);
	pck->writeD(0);
	pck->writeD(unk);
	pck->writeD(1);
	pck->writeD(0x3f800000);
	pck->writeD(0x3f801000);
	pck->writeD(1);
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_UNK27);

}

/*
0000
00000000
643D0980 - char id
643D0980 - char id
0EBB0000
00000000
FBFF0900
01000000
0000803F
0000803F
01000000
30750000
*/

#endif


////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _SM_UNK_2813_H_
#define _SM_UNK_2813_H_

inline void SM_UNK_2813(PACKET* pck, int target, int char_id)
{
	pck->CreateBufForSend();
	pck->writeD(target);
	pck->writeD(0xffffffff);
	pck->writeD(char_id);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(0x406a9e01);
	pck->writeD(0x0007fff8);
	pck->writeD(1);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(0x465eb5ff);
	pck->writeD(0);
	pck->writeD(0x402b38ff);
	pck->writeD(0);
	pck->writeD(0x164edcff);
	pck->writeD(0);
	pck->writeD(0x756994ff);
	pck->writeD(0);
	pck->writeD(0x497fdeff);
	pck->writeD(0);
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_UNK_2813);
}
/*
7C219900 - target_id
FFFFFFFF
F8922900
00000000
00000000
00000000
00000000
00000000
00000000
00000000
00000000
00000000
019E6A40 = 3.665894
F8FF0700
01000000
00000000
00000000
FFB55E46 = 14253.499023
00000000
FF382B40 = 2.675354
00000000
FFDC4E16
00000000
FF946975
00000000
FFDE7F49
00000000
00000000
*/
#endif


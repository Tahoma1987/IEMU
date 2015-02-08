////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _SM_UNK_0113_H_
#define _SM_UNK_0113_H_

inline void SM_UNK_0113(PACKET* pck, int char_id)
{
	pck->CreateBufForSend();
	pck->writeD(char_id);
	pck->writeD(0xD);
	pck->writeD(0x0007fff8);
	pck->writeD(1);
	pck->writeD(0x00070000);
	pck->writeD(0xffff);
	pck->writeD(1);
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_UNK_0113);
}
/*
1301 0000
F8922900
0D000000
F8FF0700   ......).........
01000000
00000700
FFFF0000
01000000   ................
00000000                                       ....
*/
#endif


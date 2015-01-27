////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_2d18_H_
#define _SM_UNK_2d18_H_

inline void SM_UNK_2d18(PACKET* pck, int unk)
{
	pck->CreateBufForSend();
	pck->writeD(0x3a484b00);
	pck->writeD(unk);
	pck->writeD(1);
	pck->PackSend(OPCODE_SM_UNK_2d18);
}
/*
182D 0000
00 BA 86 37
004B483A
3C000A00
01000000   .-...KH:<.......
*/
#endif


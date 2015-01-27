////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_QUESTLIST_H_
#define _SM_QUESTLIST_H_

inline void SM_QUESTLIST(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->writeD(1);
	pck->writeD(0x6d);
	pck->writeD(0x00010000);
	pck->writeD(0x403b2b00);
	pck->writeD(0x01000001);
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_QUESTLIST);


}

/*
0E00 0000
00000000
04000000
02 00 00 00
00 00 00 00
00 6D 86 3F
01 00 00 01
00 00 00 00
AE 03 00 00
00 00 86 3F
01 00 00 00
00 74 00 01
00 00 00 00
13 00 00 00
00 00 00 00
00 00 00 00
00 00 00 01
00 00 00 00
7F 01 00 00
00 00 86 3F
01 00 00 00
00 E0 00 01
00 00 00 00

*/

#endif


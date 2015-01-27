////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_630e_H_
#define _SM_UNK_630e_H_

inline void SM_UNK_630e(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeA("000000000000000008FFFFFF000000FFFFFFFFFF01000000FFFFFFFF02000000FFFFFFFF03000000FFFFFFFF04000000FFFFFFFF05000000FFFFFFFF06000000FFFFFFFF07000000FFFFFFFF");
	pck->PackSend(OPCODE_SM_UNK_630e);
}

/*
0E 63 00 00 00 00 00 00 00 00 00 00 08 FF FF FF   .c..............
00 00 00 FF FF FF FF FF 01 00 00 00 FF FF FF FF   ................
02 00 00 00 FF FF FF FF 03 00 00 00 FF FF FF FF   ................
04 00 00 00 FF FF FF FF 05 00 00 00 FF FF FF FF   ................
06 00 00 00 FF FF FF FF 07 00 00 00 FF FF FF FF   ................
*/

#endif


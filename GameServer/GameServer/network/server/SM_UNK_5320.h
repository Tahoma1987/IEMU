////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_5320_H_
#define _SM_UNK_5320_H_

inline void SM_UNK_5320(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0xFFFFFFFF);
	pck->writeD(0xFFFFFFFF);
	pck->writeD(0xFFFFFFFF);
	pck->writeD(0xFFFFFFFF);
	pck->writeD(0xFFFFFFFF);
	pck->writeD(0xFFFFFFFF);
	pck->writeD(0xFFFFFFFF);
	pck->writeD(0xFFFFFFFF);
	pck->PackSend(OPCODE_SM_UNK_5320);
}

/*
2053 0000 FFFFFFFF FFFFFFFF FFFFFFFF    S..............
FFFFFFFF FF FF FF FF FF FF FF FF FF FF FF FF   ................
*/

#endif


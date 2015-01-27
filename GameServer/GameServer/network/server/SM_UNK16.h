////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK16_H_
#define _SM_UNK16_H_

inline void SM_UNK16(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->writeD(0x41180000);
	pck->PackSend(OPCODE_SM_UNK16);
}

/*
0E98 0000 00000000 00000000               ............
*/

#endif


////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_2213_H_
#define _SM_UNK_2213_H_

inline void SM_UNK_2213(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0x0303);
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_UNK_2213);
}

/*
1322 0000 03030000 00000000               ."..........
*/

#endif


////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK24_H_
#define _SM_UNK24_H_

inline void SM_UNK24(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(1);
	pck->PackSend(OPCODE_SM_UNK24);
}

/*
0ED5 0000 01 00 00 00                           ........
*/

#endif


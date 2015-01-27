////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_0b2b_H_
#define _SM_UNK_0b2b_H_

inline void SM_UNK_0b2b(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_UNK_0b2b);
}

/*
2B 0B 00 00 00 00 00 00                           +.......
*/

#endif


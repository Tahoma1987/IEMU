////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK1_H_
#define _SM_UNK1_H_

inline void SM_UNK1(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeB(0);
	pck->PackSend(OPCODE_SM_UNK1);
}
/*
0E 44 00 00 00                                    .D...
*/
#endif




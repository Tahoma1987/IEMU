////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_4b0e_H_
#define _SM_UNK_4b0e_H_

inline void SM_UNK_4b0e(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_UNK_4b0e);
}
/*
0E4B 0000 00000000                           .K......
*/
#endif


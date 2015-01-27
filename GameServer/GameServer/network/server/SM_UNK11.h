////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK11_H_
#define _SM_UNK11_H_

inline void SM_UNK11(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_UNK11);
}

/*
0ED3 0000 00000000                           ........

*/

#endif


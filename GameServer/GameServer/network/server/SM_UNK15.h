////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK15_H_
#define _SM_UNK15_H_

inline void SM_UNK15(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0x9101);
	pck->PackSend(OPCODE_SM_UNK15);
}

/*
0ECD 0000 01910000                           ........

*/

#endif


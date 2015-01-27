////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_023e_H_
#define _SM_UNK_023e_H_

inline void SM_UNK_023e(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_UNK_023e);
}

/*
3E 02 00 00 00 00 00 00                           >.......
*/

#endif


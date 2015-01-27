////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_4f0e_H_
#define _SM_UNK_4f0e_H_

inline void SM_UNK_4f0e(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_UNK_4f0e);
}

/*
0E 4F 00 00 00 00 00 00                           .O......
*/

#endif


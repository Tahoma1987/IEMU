////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_033e_H_
#define _SM_UNK_033e_H_

inline void SM_UNK_033e(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_UNK_033e);
}

/*
3E 03 00 00 00 00 00 00                           >.......
*/

#endif


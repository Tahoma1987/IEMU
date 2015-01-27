////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_1506_H_
#define _SM_UNK_1506_H_

inline void SM_UNK_1506(PACKET* pck, int unk)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_UNK_1506);
}

/*
06 15 00 00 00 00 00 00                           ........
*/

#endif


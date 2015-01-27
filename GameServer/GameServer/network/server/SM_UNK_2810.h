////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_2810_H_
#define _SM_UNK_2810_H_

inline void SM_UNK_2810(PACKET* pck, int unk)
{
	pck->CreateBufForSend();
	pck->writeD(pck->me->id);
	pck->writeD(unk);
	pck->writeD(0x506df401);
	pck->PackSend(OPCODE_SM_UNK_2810);
}

/*
1028 0000
91FE0D80
00200000
01BD1D4E
*/

#endif


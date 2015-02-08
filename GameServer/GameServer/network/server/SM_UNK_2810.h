////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_2810_H_
#define _SM_UNK_2810_H_

inline void SM_UNK_2810(PACKET* pck, int unk, int unk2)
{
	pck->CreateBufForSend();
	pck->writeD(mychar->id);
	pck->writeD(unk);
	pck->writeD(0x406a9e00);
	pck->PackSend(OPCODE_SM_UNK_2810);
}//00 9E 6A 40

/*
1028 0000
91FE0D80
00200000
01BD1D4E
*/

#endif


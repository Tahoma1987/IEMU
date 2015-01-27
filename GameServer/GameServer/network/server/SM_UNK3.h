////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK3_H_
#define _SM_UNK3_H_

inline void SM_UNK3(PACKET* pck, int8 unk)
{
	pck->CreateBufForSend();
	pck->writeB(unk);
	pck->writeB(1);
	pck->PackSend(OPCODE_SM_UNK3);	
}

/*
0F8C
0000
00
01
*/

#endif
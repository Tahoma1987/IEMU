////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_2a0f_H_
#define _SM_UNK_2a0f_H_

inline void SM_UNK_2a0f(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0x4613);
	pck->writeD(0x030081cc);
	pck->writeD(0x8f800000);
	pck->PackSend(OPCODE_SM_UNK_2a0f);
}

/*
0F2A 0000 13460000 CC810003 000080BF   .*...F..........
*/

#endif


////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_3318_H_
#define _SM_UNK_3318_H_

inline void SM_UNK_3318(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(pck->me->target_id);
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_UNK_3318);
}

/*
1833 0000 06330280 0AEE0000               .3...3......
*/

#endif


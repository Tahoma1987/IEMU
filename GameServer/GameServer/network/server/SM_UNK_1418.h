////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_1418_H_
#define _SM_UNK_1418_H_

inline void SM_UNK_1418(PACKET* pck, int skill_id)
{
	pck->CreateBufForSend();
	pck->writeD(mychar->id);
	pck->writeD(skill_id);
	pck->writeD(0x88dd0001);
	pck->writeD(mychar->target_id);
	pck->writeD(0x00000ff8);
	pck->writeD(0);
	pck->writeD(12);
	pck->writeD(1);
	pck->writeD(0x0514);
	pck->PackSend(OPCODE_SM_USE_SKILL);
}
/*
1814 0000
CB010980 - char id
3B000200 - skill id
0100DD88
EA7F2800 - target id
F80F0000
00000000
0C000000
01000000
14050000
*/
#endif


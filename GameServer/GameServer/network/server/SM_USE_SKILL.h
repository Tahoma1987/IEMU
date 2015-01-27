////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_USE_SKILL_H_
#define _SM_USE_SKILL_H_

inline void SM_USE_SKILL(PACKET* pck, int skill_id)
{
	pck->CreateBufForSend();
	pck->writeUD(0);
	pck->writeUD(skill_id);
	pck->writeUD(0x00000f01);
	pck->writeUD(0xffffffff);
	pck->writeUD(0x3ff30000);
	pck->PackSend(OPCODE_SM_USE_SKILL);
}
/*
180C 0000
00000000
3C000A00
010C0000   ........<.......
FFFFFFFF
00005040                           ......P@
*/
#endif


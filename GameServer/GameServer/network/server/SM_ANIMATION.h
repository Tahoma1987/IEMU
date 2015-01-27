////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_ANIMATION_H_
#define _SM_ANIMATION_H_

inline void SM_ANIMATION(PACKET* pck, int unk1, int unk2)
{
	pck->CreateBufForSend();
	pck->writeD(mychar->id);
	pck->writeD(0xe33a);
	pck->writeD(unk1);
	pck->writeD(unk2);
	pck->writeD(0x42c5001a);
	pck->writeD(1);
	pck->writeD(mychar->target_id);
	pck->writeD(0x0ff8);
	pck->writeD(0);
	pck->writeD(0x3f951a15);
	pck->writeD(0x752720ff);
	pck->writeD(0);
	pck->writeD(0x49a57040);
	pck->writeD(0xff);
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_ANIMATION);
}

/*
1800 0000
58930B80 - char id
76BE0000
95933E44 - из CM_USE_SKILL
04A52B44 - из CM_USE_SKILL
68E7C141
01000000
BE35C500 - target id
3C0C0000
00000000
550CF23F
FF202A75
00000000
F04B483A
FF000000
00000000
*/

#endif


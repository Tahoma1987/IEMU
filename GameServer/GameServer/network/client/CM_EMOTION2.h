////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_EMOTION2_H_
#define _CM_EMOTION2_H_

inline void CM_EMOTION2(PACKET* pck)
{
	char emotion[128];
	int32 unk1 = pck->readD();
	int emotion_size = pck->readTstr(emotion);
	int32 unk2 = pck->readD();
	int32 unk3 = pck->readD();
	int32 unk4 = pck->readD();
	int32 unk5 = pck->readD();
	int32 unk6 = pck->readD();
	int32 unk7 = pck->readD();
	int32 unk8 = pck->readD();
	int32 unk9 = pck->readD();
	int32 unk10 = pck->readD();
	int32 unk11 = pck->readD();
	int32 unk12 = pck->readD();
	int32 unk13 = pck->readD();
	int32 unk14 = pck->readD();
	int32 unk15 = pck->readD();
	SM_EMOTION(pck, emotion);
}

/*
18AA 0100
FFFFFFFF
656D6F74696F6E5F77696e00   emotion_win
953ED730
E8A21700
0B000000
D4A21700
1E812E50
E8A21700
34789508
0B000000
E0D8ED3E
FFFFFFFF
D83E4103
0CA31700
7D41DC50
34789508               ....}A.P4x..
*/

#endif
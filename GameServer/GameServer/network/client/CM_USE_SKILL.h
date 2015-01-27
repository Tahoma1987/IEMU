////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_USE_SKILL_H_
#define _CM_USE_SKILL_H_

inline void CM_USE_SKILL(PACKET* pck)
{
	int32 unk1 = pck->readD();
	int32 char_id = pck->readD();
	int32 unk2 = pck->readD(); // 0
	int32 unk3 = pck->readD(); // 0
	int32 unk4 = pck->readD(); // 3
	int32 skill_id = pck->readD(); // 0x000a003c
	int32 unk6 = pck->readD(); // 0x77d8d501
	int32 unk7 = pck->readD(); // 0x0d
	int32 unk8 = pck->readD(); // 0x44429ed7
	int32 unk9 = pck->readD(); // 0x4417e511
	int32 unk10 = pck->readD(); // 0x419bde48
	int32 unk11 = pck->readD(); // 0x439dac8a
	SM_USE_SKILL(pck, skill_id);
	SM_UNK_1418(pck, skill_id);
	SM_UNK25(pck, skill_id, unk8, unk9, unk10, unk11);
	SM_ANIMATION(pck, unk8, unk9);
}

/*

1800 01F6
0000D877
B3F70380 - char id
00000000
00000000
03000000
3C000A00 - skill id
01D5D877
0D000000
D79E4244
11E51744
48DE9B41   ......BD...DH..A
8AAC9D43
00000000
00000000
00000000   ...C............
00000000
8AAC9D43
00000000
00000000   .......C........
0000FF00                                       ....

*/

#endif
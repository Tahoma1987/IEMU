////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK25_H_
#define _SM_UNK25_H_

inline void SM_UNK25(PACKET* pck, int skill_id, int unk1, int unk2, int unk3, int unk4)
{
	pck->writeD(mychar->id);
	pck->writeD(0x1019);
	pck->writeD(unk1);
	pck->writeD(unk2);
	pck->writeD(unk3);
	pck->writeD(0x439d8000);
	pck->writeD(unk4);
	pck->writeD(0);
	pck->writeD(mychar->id);
	pck->writeD(0x00000c01);
	pck->writeD(0);
	pck->writeD(0x3ff20c55);
	pck->writeD(0x4050aeff);
	pck->writeD(skill_id);
	pck->writeD(1);
	pck->writeD(0xffffffff);
	pck->writeD(0x40500000);
	pck->writeD(1);
	pck->writeD(0x3ff29cfe);
	pck->writeD(1);
	pck->writeD(0x3517f400);
	pck->writeD(1);
	pck->writeD(0x3c3939ff);
	pck->writeD(1);




	pck->PackSend(OPCODE_SM_UNK25);
}

/*
1800 0000
B3F70380
19100000
23A94244   . ..........#.BD
7DEF1744
E00F9C41
00809D43
8AAC9D43   }..D...A...C...C
00000000
B3F70380
3C0C0000
00000000   ........<.......
550CF23F
FFAE5040
3C000A00
01000000   U..?..P@<.......
FFFFFFFF
00005040
01000000
FE9CF23F   ......P@.......?
01000000
00F41735
01000000
FF39393C   .......5.....99<
01 00 00 00                                       ....
*/

#endif


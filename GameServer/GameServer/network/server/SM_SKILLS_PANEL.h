////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_SKILLS_PANEL_H_
#define _SM_SKILLS_PANEL_H_

inline void SM_SKILLS_PANEL(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeW(1); // unk
	pck->writeW(3); // for

	pck->writeD(1);
	pck->writeB(0);
	pck->writeW(0);
	pck->writeB(0);
	pck->writeD(0xffffffff);
	pck->writeD(0x0002007f);
	pck->writeD(0xffffffff);
	pck->writeD(0);

	pck->writeD(1);
	pck->writeB(0);
	pck->writeW(1);
	pck->writeB(0x40);
//	pck->writeD(0x40010000);
	pck->writeD(0xffffffff);
	pck->writeD(0x0002003b);
	pck->writeD(0xffffffff);
	pck->writeD(0);

	pck->writeD(1);
	pck->writeB(0);
	pck->writeW(2);
	pck->writeB(0x3c);
//	pck->writeD(0x3c020000);
	pck->writeD(0xffffffff);
	pck->writeD(0x0002006b);
	pck->writeD(0xffffffff);
	pck->writeD(0);

	pck->PackSend(OPCODE_SM_SKILLS_PANEL);
}
/*
0E4C 0000
0100
0600		- for

01000000
00000000
FFFFFFFF
4E000500
FFFFFFFF
00000000

01000000
00000140
FFFFFFFF
28000500
FFFFFFFF
00000000

01000000
00000233
FFFFFFFF
2E000500
FFFFFFFF
00000000

01000000
00000300
FFFFFFFF
64000500
FFFFFFFF
00000000

02000000
00000600
FFFFFFFF
03000000
FFFFFFFF
00000000

01000000
020000FF
FFFFFFFF
4E000500
FFFFFFFF
00000000
*/
#endif


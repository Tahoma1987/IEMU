////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK38_H_
#define _SM_UNK38_H_

inline void SM_UNK38(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0x13010000);
	pck->writeD(0x0e0c0c02);
	pck->writeD(0x00000466);
	pck->writeD(0);
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_UNK38);
}
/*
0EF3 0000
00000113
020C0C0E
66040000
00000000
00000000                           ........
*/
#endif


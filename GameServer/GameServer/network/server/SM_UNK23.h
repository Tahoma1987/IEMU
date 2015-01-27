////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK23_H_
#define _SM_UNK23_H_

inline void SM_UNK23(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->writeD(0xa8c0);
	pck->writeD(0x010d);
	pck->writeD(0x01ec30);
	pck->writeD(0);
	pck->writeD(0xd2f0);
	pck->PackSend(OPCODE_SM_UNK23);
}

/*
3F01 0000
4B000000
C0A80000
4B000000
30EC0100
00000000
F0D20000
*/

#endif


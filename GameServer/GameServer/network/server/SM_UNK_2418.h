////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_2418_H_
#define _SM_UNK_2418_H_

inline void SM_UNK_2418(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeA("E3647B002FCD00000100000001000000E3647B00FF01070000000000");
	pck->PackSend(OPCODE_SM_UNK_2418);
}
/*
18 24 00 00 E3 64 7B 00 2F CD 00 00 01 00 00 00   .$...d{./.......
01 00 00 00 E3 64 7B 00 FF 01 07 00 00 00 00 00   .....d{.........
*/
#endif


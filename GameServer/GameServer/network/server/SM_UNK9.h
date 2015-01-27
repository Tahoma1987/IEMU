////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK9_H_
#define _SM_UNK9_H_

inline void SM_UNK9(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_UNK9);


}

/*
0E8E
0000
00000000
00000000

*/

#endif


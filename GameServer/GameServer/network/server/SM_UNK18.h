////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK18_H_
#define _SM_UNK18_H_

inline void SM_UNK18(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->writeD(0xd);
	pck->writeD(1);
	pck->PackSend(OPCODE_SM_UNK18);
}

/*
0E65 0000 00000000 0D000000 01000000 .e..............
*/

#endif



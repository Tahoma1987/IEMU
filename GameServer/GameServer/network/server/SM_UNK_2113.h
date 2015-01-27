////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_2113_H_
#define _SM_UNK_2113_H_

inline void SM_UNK_2113(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_UNK_2113);
}

/*
13 21 00 00 00 00 00 00                           .!......
*/

#endif


////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK20_H_
#define _SM_UNK20_H_

inline void SM_UNK20(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0x3fa46d00);
	pck->PackSend(OPCODE_SM_UNK20);
}

/*
0F02 0000 002B3B40                           .....+;@
*/

#endif


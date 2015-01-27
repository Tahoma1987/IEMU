////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_033c_H_
#define _SM_UNK_033c_H_

inline void SM_UNK_033c(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_UNK_033c);
}

/*
3C03 0000 00000000 00000000               <...........
*/

#endif


////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_023c_H_
#define _SM_UNK_023c_H_

inline void SM_UNK_023c(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_UNK_023c);
}

/*
3C 02 00 00 00 00 00 00                           <.......
*/

#endif


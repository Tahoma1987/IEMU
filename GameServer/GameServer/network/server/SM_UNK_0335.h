////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_0335_H_
#define _SM_UNK_0335_H_

inline void SM_UNK_0335(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0xffffffff);
	pck->PackSend(OPCODE_SM_UNK_0335);
}

/*
35 03 00 00 FF FF FF FF                           5.......
*/

#endif


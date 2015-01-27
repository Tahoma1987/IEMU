////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_EXIT_H_
#define _SM_EXIT_H_

inline void SM_EXIT(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_EXIT);
}

/*
0E6F 0000 00 00 00 00                           .o......
*/

#endif


////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_1933_H_
#define _SM_UNK_1933_H_

inline void SM_UNK_1933(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_UNK_1933);

	pck->CreateBufForSend();
	pck->writeA("0200063FF1FF0E0001000000F4FF0E0001000000F5FF0E0001000000F6FF0E0001000000F7FF0E0001000000F8FF0E0001000000");
	pck->PackSend(OPCODE_SM_UNK_1a33);

}

/*
35 03 00 00 FF FF FF FF                           5.......
*/

#endif


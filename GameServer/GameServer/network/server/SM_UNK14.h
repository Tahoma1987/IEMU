////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK14_H_
#define _SM_UNK14_H_

inline void SM_UNK14(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_UNK14);
}

/*
0ECC 0000 00 00 00 00                           ........

*/

#endif


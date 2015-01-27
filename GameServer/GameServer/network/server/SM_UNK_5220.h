////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_5220_H_
#define _SM_UNK_5220_H_

inline void SM_UNK_5220(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_UNK_5220);
}
/*
2052 0000 00 00 00 00                            R......
*/
#endif




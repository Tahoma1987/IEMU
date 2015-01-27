////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK31_H_
#define _SM_UNK31_H_

inline void SM_UNK31(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(3);
	pck->PackSend(OPCODE_SM_UNK31);
}

/*
1D2B 0000
03 00 00 00                           .+......
*/

#endif


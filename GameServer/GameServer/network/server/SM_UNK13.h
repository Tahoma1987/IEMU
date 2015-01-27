////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK13_H_
#define _SM_UNK13_H_

inline void SM_UNK13(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0x1d);
	pck->writeD(5);
	pck->PackSend(OPCODE_SM_UNK13);
}

/*
3D 05 00 00 1D 00 00 00 01 00 00 00               =...........

*/

#endif


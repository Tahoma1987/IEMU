////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_610e_H_
#define _SM_UNK_610e_H_

inline void SM_UNK_610e(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->writeW(7);
	pck->writeW(0x0100);
	pck->writeW(0x0101);
	pck->writeW(0x0102);
	pck->writeW(0x0103);
	pck->writeW(0x0104);
	pck->writeW(0x0105);
	pck->writeW(0x0106);
	pck->writeW(0);
	pck->PackSend(OPCODE_SM_UNK_610e);
}
/*

*/
#endif


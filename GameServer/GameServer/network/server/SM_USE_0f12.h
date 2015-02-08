////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _SM_USE_0f12_H_
#define _SM_USE_0f12_H_

inline void SM_USE_0f12(PACKET* pck, int target)
{
	pck->CreateBufForSend();
	pck->writeD(target);
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_USE_0f12);
}
/*

*/
#endif


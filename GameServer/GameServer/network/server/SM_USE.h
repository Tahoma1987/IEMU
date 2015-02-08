////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _SM_USE_H_
#define _SM_USE_H_

inline void SM_USE(PACKET* pck, int target)
{
	pck->CreateBufForSend();
	pck->writeD(target);
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_USE);
}
/*

*/
#endif


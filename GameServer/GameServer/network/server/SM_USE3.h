////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _SM_USE3_H_
#define _SM_USE3_H_

inline void SM_USE3(PACKET* pck, int target)
{
	pck->CreateBufForSend();
	pck->writeD(target);
	pck->writeD(2);
	pck->PackSend(OPCODE_SM_USE3);
}
/*

*/
#endif


////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _SM_USE4_H_
#define _SM_USE4_H_

inline void SM_USE4(PACKET* pck, int target, int char_id)
{
	pck->CreateBufForSend();
	pck->writeD(target);
	pck->writeD(char_id);
	pck->writeB(1);
	pck->PackSend(OPCODE_SM_USE4);
}
/*

*/
#endif


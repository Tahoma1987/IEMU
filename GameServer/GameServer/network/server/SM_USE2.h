////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _SM_USE2_H_
#define _SM_USE2_H_

inline void SM_USE2(PACKET* pck, int char_id, int target)
{
	pck->CreateBufForSend();
	pck->writeD(char_id);
	pck->writeD(target);
	pck->PackSend(OPCODE_SM_USE2);
}
/*

*/
#endif


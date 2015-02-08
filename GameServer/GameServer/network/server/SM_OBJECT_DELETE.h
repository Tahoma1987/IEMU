////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _SM_OBJECT_DELETE_H_
#define _SM_OBJECT_DELETE_H_

inline void SM_OBJECT_DELETE(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(mychar->target_id);
	pck->writeD(0);							// 0 - сразу исчезает, 1 - с загосанием
	pck->PackSend(OPCODE_SM_OBJECT_DELETE);
}
/*

*/
#endif


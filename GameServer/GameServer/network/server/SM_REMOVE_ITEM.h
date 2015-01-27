////////////////////////////////////////////////
// Authors: Tahoma, karyzirus
////////////////////////////////////////////////
#ifndef _SM_REMOVE_ITEM_H_
#define _SM_REMOVE_ITEM_H_

inline void SM_REMOVE_ITEM_RESP(PACKET* pck, int16 sid)
{
	pck->CreateBufForSend();
	pck->writeW(sid);
	pck->writeW(0);
	pck->writeD(5);
	pck->PackSend(OPCODE_SM_REMOVE_ITEM);
}

/*
1302 0000
0400				- sid
5040				- ?
05000000			- action ?
*/

#endif


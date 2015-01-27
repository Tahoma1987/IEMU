////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _SM_FLY_H_
#define _SM_FLY_H_

inline void SM_FLY(PACKET* pck, uint32 char_id, int8 status)
{	
	pck->CreateBufForSend();
	pck->writeD(char_id);
	pck->writeD(status & 0xff);
	pck->PackSend(OPCODE_SM_FLY);
}
/*
100D 0000
EA7A2800
01000000               .....z(.....
*/
#endif


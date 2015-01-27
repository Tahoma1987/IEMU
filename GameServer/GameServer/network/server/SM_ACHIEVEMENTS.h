////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_ACHIEVEMENTS_H_
#define _SM_ACHIEVEMENTS_H_

inline void SM_ACHIEVEMENTS(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->writeW(0);
	pck->writeB(0);
	pck->PackSend(OPCODE_SM_ACHIEVEMENTS);
}
/*
3D02 0000 06 00000000 0000 00               =...........
*/
#endif


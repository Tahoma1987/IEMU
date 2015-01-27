////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK_2218_H_
#define _SM_UNK_2218_H_

inline void SM_UNK_2218(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0x0008b51d);
	pck->writeD(0x000081cc);
	pck->writeD(1);
	pck->writeD(1);
	pck->writeD(0x00004613);
	pck->writeD(0x000700ff);
	pck->writeD(1);
	pck->PackSend(OPCODE_SM_UNK_2218);
}

/*
1822 0000 1DB50800 CC810000 01000000   ."..............
01000000 13460000 FF000700 01000000   .....F..........
*/

#endif


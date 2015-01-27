////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK26_H_
#define _SM_UNK26_H_

inline void SM_UNK26(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(mychar->id);
	pck->writeD(0x0000bb0e);
	pck->writeD(1);
	pck->writeD(1);
	pck->writeD(mychar->id);
	pck->writeD(0x000701ff);
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_UNK26);
}

/*
0000
643D0980 - char id
0EBB0000
01000000
01000000
643D0980 - char id
FF010700
00000000
*/

#endif


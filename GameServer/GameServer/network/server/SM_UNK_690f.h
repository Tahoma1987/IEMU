////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _SM_UNK_690f_H_
#define _SM_UNK_690f_H_

inline void SM_UNK_690f(PACKET* pck, int target)
{
	pck->CreateBufForSend();
	pck->writeD(target);
	pck->writeD(0);
	pck->writeF(1000);
	pck->writeD(0);
	pck->writeF(1000);
	pck->writeD(0);
	pck->writeF(1000);
	pck->writeD(0);
	pck->writeF(1000);
	pck->PackSend(OPCODE_SM_UNK_690f);
}
/*
7C219900 - target
00000000
00007A44 = 1000
00000000
00007A44 = 1000
00000000
00007A44 = 1000
00000000
00007A44 = 1000
*/
#endif


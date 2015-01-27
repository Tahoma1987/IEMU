////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_CONNECT_H_
#define _SM_CONNECT_H_

void SM_CONNECT(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->writeD(5);				// server id
	pck->writeD(0x30303101);
	pck->writeD(0x00313031);
	pck->writeD(0);
	pck->writeD(0x200);
	pck->PackSend(OPCODE_SM_CONNECT);
}

#endif

/*
//[1e00][0502]
0000
00000000
01000000
01313030
31303100
00000000
00000000
*/
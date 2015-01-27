////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_RESTORE_CONNECTION_H_
#define _SM_RESTORE_CONNECTION_H_

void SM_RESTORE_CONNECTION(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->writeD(5);
	pck->writeD(0x3fb60000);
	pck->writeD(1);
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_RESTORE_CONNECTION);
}

#endif

/*
050B 0000
00000000
05000000
0000B63F
01000000
00000000                           ........
*/
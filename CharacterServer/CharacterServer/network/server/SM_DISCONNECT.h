////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_DISCONNECT_H_
#define _SM_DISCONNECT_H_

void SM_DISCONNECT(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->writeD(0xffffff01);
	pck->PackSend(OPCODE_SM_DISCONNECT);
	pck->Disconnect();
	log::Info(fg, "CSNetwork [%s]: user disconnect (account id: %d)\n", inet_ntoa(pck->sockstruct->from), pck->sockstruct->account_id);
}

#endif

/*
05FB 0000
00000000
01FFFFFF               ............
*/


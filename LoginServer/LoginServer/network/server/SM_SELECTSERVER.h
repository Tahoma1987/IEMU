////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _SM_SELECTSERVER_H_
#define _SM_SELECTSERVER_H_

void SM_SELECTSERVER(PACKET* pck, int numserver)
{
	if (pck->sockstruct->gameservers_info[numserver].id == -1)
		return;

	pck->CreateBufForSend();
	pck->writeW(0); // unk
	pck->writeW(0); // unk
	pck->writeD(pck->sockstruct->gameservers_info[numserver].cs_ip); // ip
	pck->writeD(pck->sockstruct->gameservers_info[numserver].cs_port); // port
	pck->writeD(pck->sockstruct->account_id); // account id
	pck->writeD(0x4c4c11be); // unk
	pck->PackSend(OPCODE_SM_SELECTSERVER);
};

#endif 
////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _SM_AUTH_H_
#define _SM_AUTH_H_

void SM_AUTH(PACKET* pck, bool succesful)
{
	if (!succesful)
	{
		pck->Disconnect();
/*		pck->CreateBufForSend();
		pck->writeB(254);
		pck->PackSend(OPCODE_SM_AUTH);*/
		return;
	}
		

	struct sockaddr_in from;
	int len = sizeof(from);
	getpeername(pck->sockstruct->socket, (struct sockaddr *)&from, &len);
	log::Info(fg, "LSNetwork [%s]: Connected account: %s\n", inet_ntoa(from.sin_addr), pck->sockstruct->account_name);

	char pack[101];
	memset(pack, 0, 100);
	strcpy(pack, pck->sockstruct->account_name);

	pck->CreateBufForSend();
	pck->writeW(0);
	pck->writeW(0);
	pck->writeBuf(pack, 100);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(0x00010100);
	pck->PackSend(OPCODE_SM_AUTH);
}

#endif
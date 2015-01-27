////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_LOBBYUSERMSG_H_
#define _SM_LOBBYUSERMSG_H_

void SM_LOBBYUSERMSG(PACKET* pck, int message)
{
	pck->CreateBufForSend();
	pck->writeD(message);
	pck->PackSend(OPCODE_SM_LOBBYUSERMSG);
}

#endif
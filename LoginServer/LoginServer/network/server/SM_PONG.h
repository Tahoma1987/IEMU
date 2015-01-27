////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _SM_PONG_H_
#define _SM_PONG_H_

void SM_PONG(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeB(0);
	pck->PackSend(OPCODE_SM_PONG);
}

#endif
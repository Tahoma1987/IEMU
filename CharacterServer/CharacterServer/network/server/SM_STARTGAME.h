////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_STARTGAME_H_
#define _SM_STARTGAME_H_

void SM_STARTGAME(PACKET* pck, int character_id)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->writeD(character_id);
	pck->writeD(inet_addr(gameserver_ip));		// ip gameserver
	pck->writeW(gameserver_port);				// port
	pck->writeW(1);								// zone
	pck->writeD(character_id);	// for gameserver
//	pck->writeD(character_id);					// for gameserver
//	pck->writeD(0x001356e2);
	pck->writeD(0xa146a5a6);
	pck->PackSend(OPCODE_SM_STARTGAME);
//	Sleep(5000);
//	pck->Disconnect();
}
#endif



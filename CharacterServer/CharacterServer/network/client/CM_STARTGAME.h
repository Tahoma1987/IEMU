////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_STARTGAME_H_
#define _CM_STARTGAME_H_

void CM_STARTGAME(PACKET* pck)
{
	Sleep(1500);
	account->status = STATUS_STARTGAME;

	int32 character_id = pck->readD();
	int32 unk2 = pck->readD(); // 0xbf6d7201
	int32 unk3 = pck->readD(); // 0
	int32 unk4 = pck->readD(); // 0
	if (use_pin_code)
		SM_GETPIN(pck, character_id);
	else
	{
		SM_PIN(pck, character_id, true);
		SM_STARTGAME(pck, character_id);
	}
}

#endif

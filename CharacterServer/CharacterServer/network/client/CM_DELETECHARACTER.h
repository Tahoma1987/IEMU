////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_DELETECHARACTER_H_
#define _CM_DELETECHARACTER_H_

void CM_DELETECHARACTER(PACKET* pck)
{
	int32 character_id = pck->readD();
	int32 unk2 = pck->readD();	// 0x40d36979
	int32 unk3 = pck->readD();	// 0x3dc88415
	int32 unk4 = pck->readD();	// 0xbee4fc27

	bool find_char = false;
	int num_characters = 0;
	for (num_characters = 0; num_characters < pck->max_characters; num_characters++)
	{
		if (pck->sockstruct->character[num_characters].id == character_id)
		{
			find_char = true;
			break;
		}
	}

	if (!find_char)
	{
		SM_LOBBYUSERMSG(pck, 13);
		return;
	}
	
	pck->sockstruct->character[num_characters].status = STATUS_DELETE_CHARACTER;
	account->status = STATUS_DELETE_CHARACTER;
	if (use_pin_code)
	{
		SM_GETPIN(pck, character_id);
	}
	else
	{
		time(&pck->sockstruct->character[num_characters].time);
		SM_PIN(pck, character_id, true);
		SM_DELETECHARACTER(pck, character_id);	
	}
}

#endif
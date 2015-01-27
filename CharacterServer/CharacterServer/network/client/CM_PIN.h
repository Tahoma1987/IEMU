////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_PIN_H_
#define _CM_PIN_H_

void CM_PIN(PACKET* pck)
{
	char pin[5];
	memset(pin, 0, 5);
	int8 unk2 = pck->readB();	// 0
	int8 action = pck->readB();
	int16 unk3 = pck->readW();	
	int32 character_id = pck->readD();
	int size_pin = pck->readBuf(pin, 4);
	uint32 unk4 = pck->readD();

	if (action == 1 || strlen(account->pin_code) < 4)
	{
		// create pin code
		pck->sql->SetPinCode(account->account_id, pin);
		SM_STARTGAME(pck, character_id);
		return;
	}
	else
	{
		// enter pin code
		if (strcmp(pin, account->pin_code) == NULL)
		{
			switch (account->status)
			{
			case STATUS_STARTGAME:
				SM_STARTGAME(pck, character_id);
				break;
			case STATUS_DELETE_CHARACTER:
				SM_DELETECHARACTER(pck, character_id);
				break;
			default:
				SM_PIN(pck, character_id, true);
			}
		}
		else
			SM_PIN(pck, character_id, true);
			
	}

}

/*
// create
027a00010000010000003135323900000000
// enter
02000002170001000000313532390021650a
*/
#endif
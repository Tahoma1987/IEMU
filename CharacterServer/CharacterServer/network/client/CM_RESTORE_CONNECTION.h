////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_RESTORE_CONNECTION_H_
#define _CM_RESTORE_CONNECTION_H_

void CM_RESTORE_CONNECTION(PACKET* pck)
{
	int character_id = pck->readD(); // 1356e2
	uint32 unk1 = pck->readD(); // 30
	uint32 unk2 = pck->readD(); // 6eddc0b0
	uint32 unk3 = pck->readD(); // d8
	account->account_id = pck->sql->GetAccountID(character_id);
	pck->sql->GetPinCode(account->account_id, account->pin_code);
	SM_RESTORE_CONNECTION(pck);
}
/*
unk1 = 0x5502
unk2 = 0x1356e2
unk3 = 0x30
unk4 = 0x010001b0
unk5 = 0x01000001
*/
#endif
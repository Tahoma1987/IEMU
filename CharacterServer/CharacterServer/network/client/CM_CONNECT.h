////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_CONNECT_H_
#define _CM_CONNECT_H_

void CM_CONNECT(PACKET* pck)
{
	account->account_id = pck->readUD();
	uint32 unk2 = pck->readUD();
	uint32 unk4 = pck->readUD();
	uint32 unk5 = pck->readUD();
	log::Info(fg, "CSNetwork [%s]: Connect (account id: %d)\n", inet_ntoa(account->from), account->account_id);
	pck->sql->GetPinCode(account->account_id, account->pin_code);
	SM_CONNECT(pck);
}

/*
028e
565c1200
62a4 // unk
17cb // id
23000000
04721700
*/

#endif
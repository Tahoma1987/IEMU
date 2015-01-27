////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_DELETECHARACTER_H_
#define _SM_DELETECHARACTER_H_

void SM_DELETECHARACTER(PACKET* pck, int character_id)
{
	char charname[32];
	memset(charname, 0, 32);

	pck->sql->GetCharacterName(character_id, charname);
	log::Info(fg, "CSNetwork [%s]: user delete character: %s (account id: %d)\n", inet_ntoa(account->from), charname, account->account_id);

	pck->CreateBufForSend();
	pck->writeD(0);
	pck->writeD(character_id);
	pck->writeD(10);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_DELETECHARACTER);

/*	pck->CreateBufForSend();
	pck->writeW(0);
	pck->writeD(character_id);
	pck->writeD(0x00013601);
	pck->PackSend(0x1705);*/
}

/*
0500 0000
00000000
0A3D2900
0A000000   .........=).....
00000000
00000000
00000000               ............

*/
#endif



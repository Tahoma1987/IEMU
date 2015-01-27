////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_PIN_H_
#define _SM_PIN_H_

void SM_PIN(PACKET* pck, int character_id, bool succesful)
{
	++account->pin_erros;
	pck->sql->UpdatePinCode(account->account_id, account->pin_erros);
	pck->CreateBufForSend();
	pck->writeD(0);
	if (account->status == STATUS_DELETE_CHARACTER)
		pck->writeB(1);
	else
		pck->writeB(0);
	pck->writeB(2);
	pck->writeD(0);
/*	pck->writeD(0x52);
	pck->writeB(1);
	pck->writeB(2);
	pck->writeW(0);
	pck->writeW(14);
	pck->writeB(5);
	pck->writeB(3);
	pck->writeW(0);
	pck->writeB(1);
	pck->writeB(0);
	pck->writeD(character_id);*/
	pck->PackSend(OPCODE_SM_PIN);
}

/*
// pin ¬á¬â¬Ú¬ß¬ñ¬ä
0500 0000
00000000
01
02
00000000         ............

// ¬à¬ê¬Ú¬Ò¬Ü¬Ñ ¬á¬â¬Ú ¬Ó¬Ó¬à¬Õ¬Ö pin
0e00
0505
0000
52000000
01
02
0000
0e00
05
03
0000
01
02
01
00
083b2600
*/
#endif



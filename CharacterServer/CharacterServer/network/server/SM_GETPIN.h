////////////////////////////////////////////////
// Authors: Tahoma, karyzir
////////////////////////////////////////////////

#ifndef _SM_GETPIN_H_
#define _SM_GETPIN_H_

void SM_GETPIN(PACKET* pck, int character_id)
{
	pck->CreateBufForSend();
	pck->writeB(0);

	if (strlen(pck->sockstruct->pin_code) == 4)
		pck->writeB(ENTER_PIN_CODE); // action
	else
		pck->writeB(CREATE_PIN_CODE);// action

	pck->writeB(account->pin_erros); // time wrong
	pck->writeB(0);
	pck->writeD(account->account_id);// account id
	
	pck->PackSend(OPCODE_SM_GETPIN);
}

#endif



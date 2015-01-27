////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UPDATE_CHARACTER_INFO_H_
#define _SM_UPDATE_CHARACTER_INFO_H_

void SM_UPDATE_CHARACTER_INFO(PACKET* pck)
{
	int num_characters = pck->sql->GetCharactersInfo(pck->sockstruct->account_id, pck->sockstruct->character, max_characters);

	pck->CreateBufForSend();
	pck->writeB(0x03);
	pck->writeB((uint8)num_characters);
	for (int i = 0; i < num_characters; i++)
	{
		pck->writeB(pck->sockstruct->character[i].cls);	// class
		pck->writeB(pck->sockstruct->character[i].lvl);	// lvl
		pck->writeB(pck->sockstruct->character[i].sex);	// sex
		pck->writeB(0x01);	// hz
	}
	pck->PackSend(OPCODE_SM_UPDATE_CHARACTER_INFO);
}

#endif
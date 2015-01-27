////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_DELETE_S_H_
#define _SM_DELETE_S_H_

void SM_DELETE_S(PACKET* pck, int character_id)
{
	pck->CreateBufForSend();
	pck->writeD(character_id);
	pck->writeD(0x0005a301);
	pck->PackSend(OPCODE_SM_DELETE_S);
}

/*
0517 0000
78492800
01A30500               ....xI(.....

*/
#endif



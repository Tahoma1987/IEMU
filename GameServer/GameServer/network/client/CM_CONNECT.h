////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_CONNECT_H_
#define _CM_CONNECT_H_

inline void CM_CONNECT(PACKET* pck)
{
	uint32 character_id = pck->readD() | 0x80000000;
	uint32 unk3 = pck->readD();
	int16 unk4 = pck->readW();
	int16 unk5 = pck->readW();
	pck->sql->GetCharacterInfo(character_id, pck->me);

	int len_charname = wcstombs(pck->me->tcharname, pck->me->charname, 18);

	pck->me->status = STATUS_CONNECT;
}

/*

*/

#endif
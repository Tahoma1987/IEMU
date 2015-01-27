////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_CHARACTERLIST_H_
#define _CM_CHARACTERLIST_H_

void CM_CHARACTERLIST(PACKET* pck)
{
	uint32 unk2 = pck->readD();
	uint32 unk3 = pck->readD();
	uint32 unk4 = pck->readD();
	uint32 unk5 = pck->readD();
	SM_CHARACTERLIST_RESPONSE(pck);
}

#endif
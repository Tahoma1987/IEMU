////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_INVENTORY_MOVE_H_
#define _CM_INVENTORY_MOVE_H_

inline void CM_INVENTORY_MOVE(PACKET* pck)
{
	int32 unk = pck->readD();
	int16 sid = pck->readW();
	int16 slot = pck->readW();

	bool find_item = false;

	for (int i = 0; i < _MAX_ITEMS_IN_INVENTORY; i++)
	{
		if (pck->me->inventory[i].sid == sid)
		{
			pck->me->inventory[i].slot = slot;
			find_item = true;
		}
	}

	if (!find_item)
		lg::Error(pck->fg, "GSInventory: Char: %s not found SID: %d\n", pck->me->tcharname, sid);

}

/*



*/

#endif
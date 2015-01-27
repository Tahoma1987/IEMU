////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_REMOVE_ITEM_H_
#define _CM_REMOVE_ITEM_H_

inline void CM_REMOVE_ITEM(PACKET* pck)
{
	bool isitem = false;
	int16 sid = pck->readW();
	int32 unk1 = pck->readW();
	int16 unk2 = pck->readD();

	for (int i = 0; i < mychar->items_in_inventory; i++)
	{
		if (isitem)
		{
			mychar->inventory[i - 1].count = mychar->inventory[i].count;
			mychar->inventory[i - 1].equip = mychar->inventory[i].equip;
			mychar->inventory[i - 1].item_id = mychar->inventory[i].item_id;
			mychar->inventory[i - 1].PlayerItemUID = mychar->inventory[i].PlayerItemUID;
			mychar->inventory[i - 1].sid = mychar->inventory[i].sid;
			mychar->inventory[i - 1].slot = mychar->inventory[i].slot;
		}
		else
			if (mychar->inventory[i].sid == sid)
				isitem = true;
	}

	SM_REMOVE_ITEM_RESP(pck, isitem);

	if (isitem)
	{
		--mychar->items_in_inventory;
		SM_REMOVE_ITEM_RESP(pck, sid);
	}
}

/*

130F 014E
0400
F539
01000000               ...N...9....

*/

#endif
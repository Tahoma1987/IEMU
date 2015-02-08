////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_USE2_H_
#define _CM_USE2_H_

inline void CM_USE2(PACKET* pck)
{
	int target = pck->readD();
	
	SM_USE3(pck, target);
	SM_UNK_2813(pck, target, mychar->id);
	SM_USE4(pck, target, mychar->id);
	SM_UNK_2810(pck, 0, 0);
	SM_USE_0f12(pck, target);
	SM_OBJECT_MOVE(pck, mychar->id, 2, mychar->pos.pos_x, mychar->pos.pos_y, mychar->pos.pos_z, mychar->pos.pos_x, mychar->pos.pos_y, mychar->pos.pos_z);
	
}

#endif
////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_ACTION_STOP_H_
#define _CM_ACTION_STOP_H_

inline void CM_ACTION_STOP(PACKET* pck)
{
	int32 unk1 = pck->readD();
	mychar->pos.pos_x = pck->readF();
	mychar->pos.pos_y = pck->readF();
	mychar->pos.pos_z = pck->readF();
	float unk2 = pck->readF();
	float unk3 = pck->readF();

	if (mychar->action == ACTION_MINING)
	{
		SM_OBJECT_DELETE(pck);
	}
	mychar->action = ACTION_NONE;
}

/*
0d000000
fbe83c44	0x443ce8fb
18905e44	0x445e9018
35f20442	0x4204f235
f0188441	0x418418f0
00003443	0x43340000
00d9353d	0x3d35d900

*/

#endif
////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_JUMP_H_
#define _CM_JUMP_H_

inline void CM_JUMP(PACKET* pck)
{
	int32 unk1 = pck->readD();
	int32 unk2 = pck->readD();	// 0xd
	mychar->pos.pos_x = pck->readF();
	mychar->pos.pos_y = pck->readF();
	mychar->pos.pos_z = pck->readF();
	mychar->pos.next_z = pck->readF();
	int32 unk3 = pck->readD();	// 3a092600
}

/*
017f7c5a
0d000000
34da4544	4445da34
f7d35444
ff5ed141	41d15eff
1c062742	4227061c
0026093a	3a092600

*/

#endif
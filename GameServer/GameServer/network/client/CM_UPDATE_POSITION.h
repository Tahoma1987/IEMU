////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_UPDATE_POSITION_H_
#define _CM_UPDATE_POSITION_H_

inline void CM_UPDATE_POSITION(PACKET* pck)
{
	int32 unk1 = pck->readD();
	mychar->pos.pos_x = pck->readF();
	mychar->pos.pos_y = pck->readF();
	mychar->pos.pos_z = pck->readF();
}

/*
0d000000
56554544
90fb5744
4d49e741

*/

#endif
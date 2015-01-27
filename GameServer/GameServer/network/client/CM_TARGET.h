////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_TARGET_H_
#define _CM_TARGET_H_

inline void CM_TARGET(PACKET* pck)
{
	pck->me->target_id = pck->readD();
	int32 unk2 = pck->readD();
}

/*
0F00 01D0
E9033000
FFC35609
*/

#endif
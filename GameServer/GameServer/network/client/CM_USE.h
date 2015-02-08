////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_USE_H_
#define _CM_USE_H_

inline void CM_USE(PACKET* pck)
{
	int target = pck->readD();

	SM_USE2(pck, mychar->id, target);	
	SM_UNK_2810(pck, 0x00000100, 0);
	SM_USE(pck, target);
}

#endif
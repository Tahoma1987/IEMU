////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_ACHIEVEMENTS_H_
#define _CM_ACHIEVEMENTS_H_

inline void CM_ACHIEVEMENTS(PACKET* pck)
{
	int8 unk2 = pck->readB();
//	SM_UNK32(pck);
//	SM_SHIPS(pck);
	SM_ACHIEVEMENTS(pck);
}

/*



*/

#endif
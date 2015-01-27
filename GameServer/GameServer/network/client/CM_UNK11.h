////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_UNK11_H_
#define _CM_UNK11_H_

inline void CM_UNK11(PACKET* pck)
{
	int8 unk2 = pck->readB();
	SM_QUEST_MAP_POINT(pck);
	SM_CHARACTER_STATS(pck);
	SM_UNK20(pck);
	SM_UNK21(pck);
	pck->me->ingame = true;
}

/*



*/

#endif
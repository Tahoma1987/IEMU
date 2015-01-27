////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_SKILL_LIST_H_
#define _CM_SKILL_LIST_H_

inline void CM_SKILL_LIST(PACKET* pck)
{
	int8 unk2 = pck->readB();
	SM_SKILL_LIST(pck);
}

/*



*/

#endif
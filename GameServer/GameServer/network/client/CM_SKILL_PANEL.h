////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_SKILL_PANEL_H_
#define _CM_SKILL_PANEL_H_

inline void CM_SKILL_PANEL(PACKET* pck)
{
	int8 unk2 = pck->readB();
//	SM_UNK_4b0e(pck);
	SM_SKILLS_PANEL(pck);
}

/*



*/

#endif
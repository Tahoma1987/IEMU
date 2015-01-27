////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_QUESTLIST_H_
#define _CM_QUESTLIST_H_

inline void CM_QUESTLIST(PACKET* pck)
{
	int8 unk2 = pck->readB();
	SM_QUESTLIST(pck);
}

/*



*/

#endif
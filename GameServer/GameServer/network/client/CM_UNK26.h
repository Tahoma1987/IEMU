////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_UNK26_H_
#define _CM_UNK26_H_

inline void CM_UNK26(PACKET* pck)
{
	int8 unk2 = pck->readB();
	SM_UNK_2113(pck);
	SM_UNK_2213(pck);
}

/*



*/

#endif
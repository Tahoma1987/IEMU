////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_UNK_5120_H_
#define _CM_UNK_5120_H_

inline void CM_UNK_5120(PACKET* pck)
{
	int8 unk2 = pck->readB();
	SM_UNK_5220(pck);
	SM_UNK_5320(pck);
}

/*

*/

#endif
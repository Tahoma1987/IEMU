////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_UNK27_H_
#define _CM_UNK27_H_

inline void CM_UNK27(PACKET* pck)
{
	int8 unk2 = pck->readB();
	SM_UNK_033c(pck);
	SM_UNK_023c(pck);
}

/*

*/

#endif
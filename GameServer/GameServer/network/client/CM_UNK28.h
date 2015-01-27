////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_UNK28_H_
#define _CM_UNK28_H_

inline void CM_UNK28(PACKET* pck)
{
	int8 unk2 = pck->readB();
	
	SM_UNK_023e(pck);
	SM_UNK_033e(pck);
	SM_UNK28(pck);
}

/*

*/

#endif
////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_UNK25_H_
#define _CM_UNK25_H_

inline void CM_UNK25(PACKET* pck)
{
	int8 unk2 = pck->readB();
	SM_UNK_1506(pck, unk2);
	SM_UNK_1606(pck, unk2);
}

/*



*/

#endif
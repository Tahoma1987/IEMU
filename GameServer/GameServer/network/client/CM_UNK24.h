////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_UNK24_H_
#define _CM_UNK24_H_

inline void CM_UNK24(PACKET* pck)
{
	int8 unk2 = pck->readB();
	SM_UNK_630e(pck);
}

/*



*/

#endif
////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_UNK5_H_
#define _CM_UNK5_H_

inline void CM_UNK5(PACKET* pck)
{
	int8 unk2 = pck->readB();
	SM_UNK8(pck);
}

/*

0E 46 01 00 B2

*/

#endif
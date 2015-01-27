////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_UNK8_H_
#define _CM_UNK8_H_

inline void CM_UNK8(PACKET* pck)
{
	int8 unk2 = pck->readB();
	SM_UNK11(pck);
	SM_UNK24(pck);
}

/*

0E D2 01 00 B2

*/

#endif
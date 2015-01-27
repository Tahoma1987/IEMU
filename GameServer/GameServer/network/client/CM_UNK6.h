////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_UNK6_H_
#define _CM_UNK6_H_

inline void CM_UNK6(PACKET* pck)
{
	int8 unk2 = pck->readB();
	SM_UNK9(pck);
}

/*

0E 8D 01 00 B2

*/

#endif
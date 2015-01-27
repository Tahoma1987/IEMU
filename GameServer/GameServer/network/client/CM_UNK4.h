////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_UNK4_H_
#define _CM_UNK4_H_

inline void CM_UNK4(PACKET* pck)
{
	int8 unk2 = pck->readB();
	SM_UNK7(pck);
}

/*
*/

#endif
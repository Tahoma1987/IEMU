////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_UNK13_H_
#define _CM_UNK13_H_

inline void CM_UNK13(PACKET* pck)
{
	int8 unk2 = pck->readB();
	SM_UNK30(pck);
	SM_UNK31(pck);
}

/*



*/

#endif
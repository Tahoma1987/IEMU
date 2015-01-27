////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_UNK19_H_
#define _CM_UNK19_H_

inline void CM_UNK19(PACKET* pck)
{
	int8 unk2 = pck->readB();
	SM_UNK_420e(pck); // ???? поставил по последовательности опкодов
}

/*



*/

#endif
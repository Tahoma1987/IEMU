////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _CM_UNK_8c18_H_
#define _CM_UNK_8c18_H_

inline void CM_UNK_8c18(PACKET* pck)
{
	int unk = pck->readB();
	SM_UNK_2118(pck);
}

#endif
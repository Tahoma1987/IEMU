////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_UNK2_H_
#define _CM_UNK2_H_

inline void CM_UNK2(PACKET* pck)
{
	int8 unk2 = pck->readB();
	pck->me->status = STATUS_SM_UNK3;
	/*
	SM_UNK3(pck, 0);
	SM_UNK3(pck, 12);
	SM_UNK3(pck, 19);
	SM_UNK3(pck, 15);
	SM_UNK3(pck, 12);
	SM_UNK3(pck, 11);
	SM_UNK4(pck);*/
}

/*

*/

#endif
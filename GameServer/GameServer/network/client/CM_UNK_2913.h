////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _CM_UNK_2913_H_
#define _CM_UNK_2913_H_

inline void CM_UNK_2913(PACKET* pck)
{
	int unk1 = pck->readD();
	int16 unk2 = pck->readW();
	int16 unk3 = pck->readW();
	int8 unk4 = pck->readB();

	SM_UNK_0113(pck, mychar->id);
}

/*
1329 0167
7C219900
0100
1700
43            .).g|!......C
*/

#endif
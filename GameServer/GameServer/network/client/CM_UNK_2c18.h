////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_UNK_2c18_H_
#define _CM_UNK_2c18_H_

inline void CM_UNK_2c18(PACKET* pck)
{
	int32 unk1 = pck->readD();
	int32 unk2 = pck->readD();
	SM_UNK_2d18(pck, unk1);
}

/*

182C 0100
3C000A00
01A21700               .,..<.......

*/

#endif
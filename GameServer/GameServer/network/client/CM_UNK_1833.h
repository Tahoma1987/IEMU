////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_UNK_1833_H_
#define _CM_UNK_1833_H_

inline void CM_UNK_1833(PACKET* pck)
{
	uint16 unk2 = pck->readW();
	uint8 unk3 = pck->readB();
	SM_UNK_1933(pck);
	SM_UNK_1a33(pck, unk3);
}

/*
33 18 01 00 00                                    3....
33 18 01 00 01                                    3....
33 18 01 00 02                                    3....
33 18 01 00 03                                    3....
33 18 01 00 04                                    3....
33 18 01 00 05                                    3....


*/

#endif
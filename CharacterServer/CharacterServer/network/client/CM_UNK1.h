////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_UNK1_H_
#define _CM_UNK1_H_

void CM_UNK1(PACKET* pck)
{
	uint16 unk1 = pck->readW();
	uint32 unk2 = pck->readD();
	SM_UPDATE_CHARACTER_INFO(pck);
}

/*
0204
051d
01030300
01010402
*/

#endif


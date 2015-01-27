////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_CHARACTER_STYLE_H_
#define _CM_CHARACTER_STYLE_H_

inline void CM_CHARACTER_STYLE(PACKET* pck)
{
	int32 unk2 = pck->readD();
	SM_CHARACTER_STYLE(pck);
}

/*



*/

#endif
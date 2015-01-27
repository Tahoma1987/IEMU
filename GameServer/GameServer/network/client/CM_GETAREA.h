////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_GETAREA_H_
#define _CM_GETAREA_H_

inline void CM_GETAREA(PACKET* pck)
{
	int8 unk2 = pck->readB();
	SM_SETAREA(pck);	
}

/*



*/

#endif
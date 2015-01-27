////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _CM_FLY_H_
#define _CM_FLY_H_

inline void CM_FLY(PACKET* pck)
{
	int8 status = pck->readB();
	mychar->fly = status > 0 ? true : false;
	SM_FLY(pck, mychar->id, status);
}

/*
10 00 01 A8 01                                    .....
*/

#endif
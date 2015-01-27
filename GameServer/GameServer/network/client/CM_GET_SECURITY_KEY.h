////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_GET_SECURITY_KEY_H_
#define _CM_GET_SECURITY_KEY_H_

inline void CM_GET_SECURITY_KEY(PACKET* pck)
{
	int8 unk2 = pck->readB();
	SM_SECURITY_KEY(pck);
}

/*

0E 90 01 00 B2

*/

#endif
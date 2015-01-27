////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_SECURITY_KEY_H_
#define _CM_SECURITY_KEY_H_

inline void CM_SECURITY_KEY(PACKET* pck)
{
	WCHAR secure_key[128];
	int16 size_key = pck->readW();
	int read_size = pck->readBuf((char*)secure_key, size_key * 2);
//	pck->Disconnect();
}

/*
01560800
35003700
38003400
68006a00
0a00bfe1
*/

#endif
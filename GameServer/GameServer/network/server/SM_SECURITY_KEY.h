////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_SECURITY_KEY_H_
#define _SM_SECURITY_KEY_H_

inline void SM_SECURITY_KEY(PACKET* pck)
{
	char security[] = "45784hj/f4";
	WCHAR tmp[64];
	memset(tmp, 0, sizeof(tmp));
	mbstowcs(tmp, security, strlen(security));
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->writeUstr(tmp, true);
//	pck->writeA("0B003300350037013800340068006A002F01660034010C000000");
	pck->writeW(0);
//	pck->writeW(0);
//	pck->writeD(0);
//	pck->writeUstr(L"35784hj/");
	pck->PackSend(OPCODE_SM_SECURITY_KEY);
}

/*
0E 00 00 00 00 00 00 00 0B 00 33 00 35 00 37 01   ..........3.5.7.
38 00 34 00 68 00 6A 00 2F 01 66 00 34 01 0C 00   8.4.h.j./.f.4...
01 00

*/

#endif


////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_CHAT_H_
#define _CM_CHAT_H_

inline void CM_CHAT(PACKET* pck)
{	
	char str[1024];
	uint32 unk2 = pck->readD();
	uint32 unk3 = pck->readD();
	uint32 unk4 = pck->readD();
	uint32 unk5 = pck->readD();
	uint32 unk6 = pck->readD();
	uint32 unk7 = pck->readD();
	uint32 unk8 = pck->readD();
	uint32 unk9 = pck->readD();
	uint32 unk10 = pck->readD();
	uint32 unk11 = pck->readD();
	uint16 unk12 = pck->readW();
	int len = pck->read2Str(str);

	if (len > 510)
		return;
	memcpy(mychar->chat_msg, str, len + 1);
	mychar->status = STATUS_CHAT;
	
}

/*
1100 01AF
01000000
00000000
00000000
00000000
00000000
00000000
00000000
00000000
00000000
00000000
2498
1000
31313131313131313131313131313131   1111111111111111
0000                                             ..

*/

#endif
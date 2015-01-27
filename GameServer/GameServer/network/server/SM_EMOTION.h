////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_EMOTION_H_
#define _SM_EMOTION_H_

inline void SM_EMOTION(PACKET* pck, char* emotion)
{
	char str[70];
	memset(str, 0, 69);
	strcpy(str, emotion);

	pck->CreateBufForSend();
	pck->writeD(mychar->id);
	if (mychar->target_id == 0)
		pck->writeD(0xffffffff);
	else
		pck->writeD(mychar->target_id);
	pck->writeBuf(str, 68);
	pck->PackSend(OPCODE_SM_EMOTION);
}

/*
18AB 0000
13F50880 - char_id
FFFFFFFF - target_id ?
65 6D 6F 74   ............emot
69 6F 6E 5F 77 69 6E 00 00 00 00 00 00 00 00 00   ion_win.........
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00   ................
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00   ................
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00   ................
*/

#endif
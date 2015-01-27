////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK5_H_
#define _SM_UNK5_H_

// ¬Þ¬ã¬ñ¬Ô¬Ñ ¬á¬â¬Ú ¬Ó¬ç¬à¬Õ¬Ö ¬Ó ¬Ú¬Ô¬â¬å
inline void SM_UNK5(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeW(0x0101);
	pck->PackSend(OPCODE_SM_UNK4);

	pck->CreateBufForSend();
	pck->writeW(0x0c01);
	pck->PackSend(OPCODE_SM_UNK4);

	pck->CreateBufForSend();
	pck->writeW(0x0f01);
	pck->PackSend(OPCODE_SM_UNK4);

	pck->CreateBufForSend();
	pck->writeW(0x0c01);
	pck->PackSend(OPCODE_SM_UNK4);

	pck->CreateBufForSend();
	pck->writeW(0x0b01);
	pck->PackSend(OPCODE_SM_UNK4);

}

/*
1e00
0efe
0000
00000000
01010001
01010001
01010100
01000000
00ffffff
*/

#endif

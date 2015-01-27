////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK28_H_
#define _SM_UNK28_H_

inline void SM_UNK28(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeA("B60000000000803F01A24835");
	pck->PackSend(OPCODE_SM_UNK28);
	pck->CreateBufForSend();
	pck->writeA("630000000000A04101A24835");
	pck->PackSend(OPCODE_SM_UNK28);
	pck->CreateBufForSend();
	pck->writeA("770000000000484201A24835");
	pck->PackSend(OPCODE_SM_UNK28);
	pck->CreateBufForSend();
	pck->writeA("B6000000000000000100C701");
	pck->PackSend(OPCODE_SM_UNK28);
	pck->CreateBufForSend();
	pck->writeA("750000000000A04101A24835");
	pck->PackSend(OPCODE_SM_UNK28);
	return;
	
	pck->writeD(0xb6);
	pck->writeD(0x3f800000);
	pck->writeD(0x35e0d801);
	pck->PackSend(OPCODE_SM_UNK28);

}

/*
0F21 0000
B6000000
0000803F
01E58434
*/

#endif


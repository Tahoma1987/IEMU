////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _SM_QUESTSTATEMSG_H_
#define _SM_QUESTSTATEMSG_H_

inline void SM_QUESTSTATEMSG(PACKET* pck)// , int num_complate)
{
	pck->CreateBufForSend();
	pck->writeW(0);
	pck->writeW(3);		// num compate
	pck->PackSend(OPCODE_SM_QUESTSTATEMSG);
}
/*
140A 0000
0000
0100                           ........
*/
#endif


////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_UNK35_H_
#define _SM_UNK35_H_

inline void SM_UNK35(PACKET* pck)
{
	pck->CreateBufForSend();
	pck->writeA("0003000000000000FFFFFFFFDF00000000000000DF00000000000000DF00000000000000DF00000000000000FFFFFFFFDF00000000000000DF00000000000000DF00000000000000DF00000000000000FFFFFFFFDF00000000000000DF00000000000000DF00000000000000DF0000000000000001000000FFFFFFFFDF00000000000000DF00000000000000DF00000000000000DF00000000000000FFFFFFFFDF00000000000000DF00000000000000DF00000000000000DF00000000000000FFFFFFFFDF00000000000000DF00000000000000DF00000000000000DF0000000000000002000000FFFFFFFFDF00000000000000DF00000000000000DF00000000000000DF00000000000000FFFFFFFFDF00000000000000DF00000000000000DF00000000000000DF00000000000000FFFFFFFFDF00000000000000DF00000000000000DF00000000000000DF00000000000000");
	pck->PackSend(OPCODE_SM_UNK35);
}
#endif

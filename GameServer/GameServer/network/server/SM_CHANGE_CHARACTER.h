////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_CHANGE_CHARACTER_H_
#define _SM_CHANGE_CHARACTER_H_

inline void SM_CHANGE_CHARACTER(PACKET* pck, int8 action)
{
	pck->CreateBufForSend();
	pck->writeB(action);
	pck->PackSend(OPCODE_SM_CHANGE_CHARACTER);
}

/*
                      ........
*/

#endif


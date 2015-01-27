////////////////////////////////////////////////
// Authors: Tahoma, karyzirus
////////////////////////////////////////////////
#ifndef _SM_REMOVE_ITEM_RESP_H_
#define _SM_REMOVE_ITEM_RESP_H_

inline void SM_REMOVE_ITEM_RESP(PACKET* pck, bool isitem)
{	
	pck->CreateBufForSend();
	pck->writeD(isitem == true ? (int)0 : (int)1);	// 0 - ок, 3 - нет предмета
	pck->PackSend(OPCODE_SM_REMOVE_ITEM_RESP);
}

/*
1310 0000
00000000                           ........

1 - произошла системная ошибка
2 - содержание не может быть использовано ещё
*/

#endif


////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _CM_SELECTSERVER_H_
#define _CM_SELECTSERVER_H_

void CM_SELECTSERVER(PACKET* pck)
{
	int32 numserver = pck->readD();	// номер выбранного сервера
	int32 unk2 = pck->readD();		// 0x00175b54
	int32 unk3 = pck->readD();		// 0x05322d24
	int32 unk4 = pck->readD();		// 0x05384824
	SM_SELECTSERVER(pck, numserver);
}

#endif
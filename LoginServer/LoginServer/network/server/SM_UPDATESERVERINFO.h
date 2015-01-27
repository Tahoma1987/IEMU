////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _SM_UPDATESERVERINFO_H_
#define _SM_UPDATESERVERINFO_H_

void SM_UPDATESERVERINFO(PACKET* pck)
{
	if (pck->sockstruct->send_serverlist)
	{
		pck->CreateBufForSend();
		pck->writeD(1);
		pck->writeD(1);
		pck->writeD(1);			
		pck->writeD(2);
		pck->PackSend(OPCODE_SM_UPDATESERVERINFO);
		
	}
}

#endif SM_UPDATESERVERINFO
/*
<part name = "crypt_flag" type = "h" / >
<part name = "numserver" type = "d" / >
<part name = "unk1" type = "d" / >
<part name = "unk2" type = "d" / >
<part name = "unk3" type = "d" / >
*/
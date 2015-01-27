////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _OPCODES_H_
#define _OPCODES_H_

//////////////////////////////////////////////////////////////////////
// OPCODES ///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

// SYSTEM ////////////////////////////////////////////////////////////
#define OPCODE_CM_PING							0x0165		// ok
#define OPCODE_SM_PONG							0x0165		// ok
#define OPCODE_CM_CONNECT						0x0105		// 
#define OPCODE_SM_CONNECT						0x0205		// 
#define OPCODE_CM_DISCONNECT					0xfa05		// 
#define OPCODE_SM_DISCONNECT					0xfb05		// 
#define OPCODE_CM_RESTORE_CONNECTION			0x0a05		//
#define OPCODE_SM_RESTORE_CONNECTION			0x0b05		//
#define OPCODE_CM_CHARACTERLIST					0x1005		// 
#define OPCODE_SM_CHARACTERLIST_RESPONSE		0x1105		// 
#define OPCODE_CM_CHECKCHARACTERNAME			0x1405		// 
#define OPCODE_SM_LOBBYUSERMSG					0x1505		// 
#define OPCODE_CM_CREATECHARACTER				0x1205		//
#define OPCODE_SM_CREATECHARACTER				0x1305		//
#define OPCODE_CM_DELETECHARACTER				0x0e05		//
#define OPCODE_SM_DELETECHARACTER				0x1605		//
#define OPCODE_SM_DELETE_S						0x1705		//
#define OPCODE_SM_GETPIN						0x0305		//
#define OPCODE_CM_PIN							0x0405		//
#define OPCODE_SM_PIN							0x0505		//
#define OPCODE_CM_STARTGAME						0x2005		//
#define OPCODE_SM_STARTGAME						0x2105		//
#define OPCODE_CM_UNK1							0x1a05		//
#define OPCODE_SM_UPDATE_CHARACTER_INFO			0x1d05		//
#define OPCODE_CM_UNK2							0x1e13		//

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////


#include "inc_opcodes.h"


bool LSOpcodes(PACKET* pck)
{
	char bindbg[2];
	memset(bindbg, 0, 2);

	switch (pck->opcode)
	{
		OPCODE(OPCODE_CM_PING, CM_PING);
		OPCODE(OPCODE_CM_CONNECT, CM_CONNECT);
		OPCODE(OPCODE_CM_DISCONNECT, CM_DISCONNECT);
		OPCODE(OPCODE_CM_RESTORE_CONNECTION, CM_RESTORE_CONNECTION);
		OPCODE(OPCODE_CM_CHARACTERLIST, CM_CHARACTERLIST);
		OPCODE(OPCODE_CM_CHECKCHARACTERNAME, CM_CHECKCHARACTERNAME);
		OPCODE(OPCODE_CM_CREATECHARACTER, CM_CREATECHARACTER);
		OPCODE(OPCODE_CM_DELETECHARACTER, CM_DELETECHARACTER);
		OPCODE(OPCODE_CM_PIN, CM_PIN);
		OPCODE(OPCODE_CM_STARTGAME, CM_STARTGAME);
		OPCODE(OPCODE_CM_UNK1, CM_UNK1);
		OPCODE(OPCODE_CM_UNK2, CM_UNK2);


	default:
	{
		/// DEBUG
		char* fordebug = pck->GetPacketPointer();
		log::Debug(fg, "C->S: op[%02x] ", pck->opcode);
		for (int i = 0; i < pck->packet_len; i++)
		{
			if ((uint8)fordebug[i] > 0x20 && (uint8)fordebug[i] <= 'z')
			{
				bindbg[0] = (uint8)fordebug[i];
				log::Notify(fg, bindbg);
			}
			else
			{
				log::Notify(fg, ".");
			}
		}
		log::Notify(fg, "\n");

		log::Debug(fg, "C->S: op[%04x] ", pck->opcode);
		for (int i = 0; i < pck->packet_len; i++)
		{
			log::Notify(fg, "%02x", (uint8)fordebug[i]);
		}
		log::Notify(fg, "\n");
	}
		/// !DEBUG
	}
	return true;
}

void opcodes(PACKET* pck)
{
	pck->PackCreate();

	if (!LSOpcodes(pck))
	{

	}
}

#endif _OPCODES_H_



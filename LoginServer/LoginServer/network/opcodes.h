////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _OPCODES_H_
#define _OPCODES_H_

//////////////////////////////////////////////////////////////////////
// OPCODES ///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

// SYSTEM ////////////////////////////////////////////////////////////
#define OPCODE_CM_PING							0x0165		// +
#define OPCODE_SM_PONG							0x0165		// +
#define OPCODE_CM_AUTH							0x030b		// +
#define OPCODE_SM_AUTH							0x040b		// +
#define OPCODE_CM_SERVER_LIST					0x0a0b		//
#define OPCODE_SM_SERVER_LIST					0x0b0b		//
#define OPCODE_CM_SELECTSERVER					0x140b		//
#define OPCODE_SM_SELECTSERVER					0x150b		//
#define OPCODE_SM_UPDATESERVERINFO				0x0e0b		//

// ¬¥¬Ý¬ñ ¬Þ¬à¬Ö¬Ô¬à ¬Ý¬Ñ¬å¬ß¬é¬Ö¬â¬Ñ
#define OPCODE_CM_MY_LAUNCHER_LOGIN				0xfeff		// +
#define OPCODE_SM_MY_LAUNCHER_LOGIN				0xfeff		// +

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////


#include "inc_opcodes.h"


bool LSOpcodes(PACKET* pck)
{
	char bindbg[2];
	memset(bindbg, 0, 2);

	switch (pck->opcode)
	{
		OPCODE(OPCODE_CM_AUTH, CM_AUTH);
		OPCODE(OPCODE_CM_PING, CM_PING);
		OPCODE(OPCODE_CM_SERVER_LIST, CM_SERVER_LIST);
		OPCODE(OPCODE_CM_SELECTSERVER, CM_SELECTSERVER);

		// ¬¥¬Ý¬ñ ¬Þ¬à¬Ö¬Ô¬à ¬Ý¬Ñ¬å¬ß¬é¬Ö¬â¬Ñ
		OPCODE(OPCODE_CM_MY_LAUNCHER_LOGIN, CM_MY_LAUNCHER_LOGIN);

		/// DEBUG
	default:
	{
		   char* fordebug = pck->GetPacketPointer();
		   log::Debug(fg, "C->S: op[%04x] ", pck->opcode);
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



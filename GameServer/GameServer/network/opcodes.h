////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _OPCODES_H_
#define _OPCODES_H_


namespace OPCODES
{
	//////////////////////////////////////////////////////////////////////
	// OPCODES ///////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

#define OPCODE_CM_CONNECT						0x010e		// 
#define OPCODE_SM_CONNECT						0x020e		// 
#define OPCODE_CM_DISCONNECT					0xfa0e		// 
#define OPCODE_SM_DISCONNECT					0xfb0e		// 
#define OPCODE_CM_EXIT							0x6e0e		//
#define OPCODE_SM_EXIT							0x6f0e		//
#define OPCODE_SM_CHANGE_CHARACTER				0x700e		//
#define OPCODE_CM_INVENTORY						0x340e		// ok
#define OPCODE_SM_INVENTORY_RESPONSE			0x350e		// ok
#define OPCODE_CM_INVENTORY_MOVE				0x1e13		// ok
#define OPCODE_CM_GETAREA						0x320e		//
#define OPCODE_SM_SETAREA						0x330e		// 
#define OPCODE_CM_QUESTLIST						0x390e		// 
#define OPCODE_SM_QUESTLIST						0x3a0e		// 
#define OPCODE_CM_SKILL_LIST					0x360e		// 
#define OPCODE_SM_SKILL_LIST					0x380e		//
#define OPCODE_CM_SKILL_PANEL					0x4a0e		// 
#define OPCODE_SM_SKILLS_PANEL					0x4c0e		//

#define OPCODE_CM_MOVE_MOUSESET					0x0110		//
#define OPCODE_SM_MOVE_MOUSESET					0x0210		//
#define OPCODE_SM_OBJECT_MOVE					0x0310		//
#define OPCODE_CM_ACTION_STOP					0x0410		//
#define OPCODE_CM_MOVE							0x0610		//
#define OPCODE_SM_MOVE							0x0710		//
#define OPCODE_CM_JUMP							0x0810		//
#define OPCODE_CM_UPDATE_POSITION				0x0a10		//
#define OPCODE_CM_FLY							0x0c10		// ok
#define OPCODE_SM_FLY							0x0d10		// ok



#define OPCODE_CM_CHARACTER_STYLE				0x0127		// 
#define OPCODE_CM_ACHIEVEMENTS					0x013d		// 
#define OPCODE_SM_ACHIEVEMENTS					0x023d		//
#define OPCODE_CM_GET_SECURITY_KEY				0x900e		// 
#define OPCODE_SM_SECURITY_KEY					0x910e		// 
#define OPCODE_CM_SECURITY_KEY					0x920e		// 
#define OPCODE_CM_CHAT							0x0111		// 
#define OPCODE_SM_CHAT							0x0311		//


#define OPCODE_SM_CHARACTER_STATS				0x010f		// 
#define OPCODE_CM_UNK27							0x013c		// 
#define OPCODE_CM_UNK28							0x013e		// 
#define OPCODE_SM_UNK23							0x013f		// 
#define OPCODE_SM_UNK20							0x020f		// 
#define OPCODE_SM_UNK21							0x030f		// 
#define OPCODE_CM_EMOTION						0x0118		//
#define OPCODE_CM_EMOTION2						0xaa18		//
#define OPCODE_SM_EMOTION						0xab18		//
#define OPCODE_SM_CHARACTER_STYLE				0x0227		//
#define OPCODE_SM_UNK_023c						0x023c		//
#define OPCODE_SM_UNK_023e						0x023e		//
#define OPCODE_SM_UNK_0335						0x0335		//
#define OPCODE_SM_UNK_033c						0x033c		//
#define OPCODE_SM_UNK32							0x033d		//
#define OPCODE_SM_UNK_033e						0x033e		//
#define OPCODE_SM_UNK29							0x033f		//
#define OPCODE_SM_SHIPS							0x043d		//
#define OPCODE_SM_UNK13							0x053d		// 
#define OPCODE_CM_UNK17							0x0a2b		// 
#define OPCODE_SM_UNK_0b2b						0x0b2b		//
#define OPCODE_SM_UNK_0c2b						0x0c2b		//
#define OPCODE_CM_USE_SKILL						0x0b18		//
#define OPCODE_SM_USE_SKILL						0x0c18		//
#define OPCODE_CM_UNK25							0x1406		// 
#define OPCODE_SM_UNK_1418						0x1418		//
#define OPCODE_SM_UNK_1506						0x1506		//
#define OPCODE_SM_UNK_1606						0x1606		//
#define OPCODE_SM_PLAYER_INFO					0x1710		//
#define OPCODE_CM_UNK_1833						0x1833		//
#define OPCODE_SM_UNK_1933						0x1933		//
#define OPCODE_SM_UNK_1a33						0x1a33		//
#define OPCODE_SM_GAMEOBJECT_SPAWN				0x1b10		// 
#define OPCODE_CM_GAMEOBJECT_INFO				0x1f10		// 
#define OPCODE_SM_ANIMATION						0x1f18		//
#define OPCODE_CM_UNK26							0x2013		// 
#define OPCODE_SM_UNK25							0x2018		// 
#define OPCODE_SM_UNK28							0x210f		// 
#define OPCODE_SM_UNK_2113						0x2113		//
#define OPCODE_SM_UNK_2118						0x2118		//
#define OPCODE_SM_UNK_2213						0x2213		//
#define OPCODE_SM_UNK_2218						0x2218		//
#define OPCODE_SM_UNK26							0x2318		// 
#define OPCODE_SM_UNK5							0x230f		// 
#define OPCODE_SM_UNK_2418						0x2418		//
#define OPCODE_SM_UNK_2810						0x2810		//
#define OPCODE_CM_UNK13							0x291d		// 
#define OPCODE_SM_UNK_2a0f						0x2a0f		//
#define OPCODE_SM_UNK30							0x2a1d		//
#define OPCODE_SM_UNK31							0x2b1d		//
#define OPCODE_CM_UNK_2c18						0x2c18		//
#define OPCODE_SM_UNK_2d18						0x2d18		//
#define OPCODE_SM_UNK27							0x3218		// 
#define OPCODE_SM_QUEST_MESSAGE					0x3311		//
#define OPCODE_SM_UNK_3318						0x3318		//
#define OPCODE_SM_SKILL_BUF						0x3418		//
#define OPCODE_CM_UNK4							0x3c0e		// 
#define OPCODE_SM_UNK7							0x3d0e		// 
#define OPCODE_CM_UNK20							0x3f0e		// 
#define OPCODE_SM_UNK_400e						0x400e		//
#define OPCODE_CM_UNK19							0x410e		// 
#define OPCODE_SM_UNK_420e						0x420e		//
#define OPCODE_SM_UNK1							0x440e		// 
#define OPCODE_CM_UNK5							0x460e		// 
#define OPCODE_SM_UNK8							0x470e		// 
#define OPCODE_SM_UNK_4b0e						0x4b0e		//
#define OPCODE_CM_UNK15							0x4e0e		// 
#define OPCODE_SM_UNK_4f0e						0x4f0e		//
#define OPCODE_CM_UNK_5120						0x5120		//
#define OPCODE_SM_UNK_5220						0x5220		//
#define OPCODE_SM_UNK_5320						0x5320		//
#define OPCODE_CM_UNK23							0x600e		// 
#define OPCODE_SM_UNK_610e						0x610e		//
#define OPCODE_CM_UNK24							0x620e		// 
#define OPCODE_SM_UNK_630e						0x630e		//
#define OPCODE_CM_UNK12							0x640e		// 
#define OPCODE_SM_UNK18							0x650e		// 
#define OPCODE_CM_TARGET						0x640f		//
#define OPCODE_SM_UNK3							0x8c0f		// 
#define OPCODE_CM_UNK6							0x8d0e		// 
#define OPCODE_SM_UNK9							0x8e0e		// 
#define OPCODE_CM_UNK10							0x970e		// 
#define OPCODE_SM_UNK16							0x980e		// 
#define OPCODE_SM_UNK_9713						0x9713		//
#define OPCODE_SM_UNK_9813						0x9813		//
#define OPCODE_SM_UNK40							0x9913		//
#define OPCODE_SM_UNK35							0x9b13		//
#define OPCODE_SM_UNK_9c13						0x9c13		//
#define OPCODE_SM_UNK_9d13						0x9d13		//
#define OPCODE_SM_UNK_9e13						0x9e13		//
#define OPCODE_CM_UNK11							0xa00e		// 
#define OPCODE_SM_QUEST_MAP_POINT				0xa10e		// 
#define OPCODE_SM_UNK33							0xa113		//
#define OPCODE_CM_UNK9							0xcb0e		// 
#define OPCODE_SM_UNK14							0xcc0e		// 
#define OPCODE_SM_UNK15							0xcd0e		// 
#define OPCODE_CM_UNK8							0xd20e		// 
#define OPCODE_SM_UNK11							0xd30e		// 
#define OPCODE_SM_UNK24							0xd50e		// 
#define OPCODE_SM_UNK38							0xf30e		//
#define OPCODE_CM_UNK2							0xfd0e		// 
#define OPCODE_SM_UNK4							0xfe0e		// 
#define OPCODE_CM_REMOVE_ITEM					0x0f13		// 
#define OPCODE_SM_REMOVE_ITEM_RESP				0x1013		//
#define OPCODE_SM_REMOVE_ITEM					0x0213		//

#define OPCODE_CM_USE0							0x0112		//
#define OPCODE_SM_USE0							0x0212		//
#define OPCODE_CM_USE							0x0312		//
#define OPCODE_SM_USE							0x0412		//
#define OPCODE_SM_USE2							0x0512		//
#define OPCODE_CM_USE2							0x0a12		//
#define OPCODE_SM_USE4							0x0e12		//
#define OPCODE_SM_USE_0f12						0x0f12		//
#define OPCODE_SM_USE3							0x1112		//

#define OPCODE_SM_UNK_0113						0x0113		//
#define OPCODE_SM_UNK_2813						0x2813		//
#define OPCODE_SM_UNK_690f						0x690f		//
#define OPCODE_SM_QUESTSTATEMSG					0x0a14		//
#define OPCODE_CM_UNK_8c18						0x8c18		//
#define OPCODE_CM_UNK_2913						0x2913		//
#define OPCODE_SM_OBJECT_DELETE					0x1c10		//
#define OPCODE_CM_SKILLS_PANEL_MOVE				0x480e		//


// SYSTEM
#define OPCODE_CM_PING							0x0165		// ok
#define OPCODE_SM_PONG							0x0165		// ok


	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////


#include "inc_opcodes.h"


	inline bool LSOpcodes(PACKET* pck, FILE* fg)
	{
		char bindbg[2];

		switch (pck->opcode)
		{
			OPCODE(OPCODE_CM_PING, CM_PING);
			OPCODE(OPCODE_CM_CONNECT, CM_CONNECT);
			OPCODE(OPCODE_CM_DISCONNECT, CM_DISCONNECT);
			OPCODE(OPCODE_CM_SECURITY_KEY, CM_SECURITY_KEY);
			OPCODE(OPCODE_CM_UNK2, CM_UNK2);
			OPCODE(OPCODE_CM_GETAREA, CM_GETAREA);
			OPCODE(OPCODE_CM_UNK4, CM_UNK4);
			OPCODE(OPCODE_CM_UNK5, CM_UNK5);
			OPCODE(OPCODE_CM_UNK6, CM_UNK6);
			OPCODE(OPCODE_CM_GET_SECURITY_KEY, CM_GET_SECURITY_KEY);
			OPCODE(OPCODE_CM_UNK8, CM_UNK8);
			OPCODE(OPCODE_CM_UNK9, CM_UNK9);
			OPCODE(OPCODE_CM_UNK10, CM_UNK10);
			OPCODE(OPCODE_CM_UNK11, CM_UNK11);
			OPCODE(OPCODE_CM_UNK12, CM_UNK12);
			OPCODE(OPCODE_CM_UNK13, CM_UNK13);
			OPCODE(OPCODE_CM_ACHIEVEMENTS, CM_ACHIEVEMENTS);
			OPCODE(OPCODE_CM_UNK15, CM_UNK15);
			OPCODE(OPCODE_CM_INVENTORY, CM_INVENTORY);
			OPCODE(OPCODE_CM_UNK17, CM_UNK17);
			OPCODE(OPCODE_CM_SKILL_LIST, CM_SKILL_LIST);
			OPCODE(OPCODE_CM_UNK19, CM_UNK19);
			OPCODE(OPCODE_CM_UNK20, CM_UNK20);
			OPCODE(OPCODE_CM_SKILL_PANEL, CM_SKILL_PANEL);
			OPCODE(OPCODE_CM_CHARACTER_STYLE, CM_CHARACTER_STYLE);
			OPCODE(OPCODE_CM_UNK23, CM_UNK23);
			OPCODE(OPCODE_CM_UNK24, CM_UNK24);
			OPCODE(OPCODE_CM_UNK25, CM_UNK25);
			OPCODE(OPCODE_CM_UNK26, CM_UNK26);
			OPCODE(OPCODE_CM_UNK27, CM_UNK27);
			OPCODE(OPCODE_CM_UNK28, CM_UNK28);
			OPCODE(OPCODE_CM_GAMEOBJECT_INFO, CM_GAMEOBJECT_INFO);
			OPCODE(OPCODE_CM_EXIT, CM_EXIT);
			OPCODE(OPCODE_CM_UNK_5120, CM_UNK_5120);
			OPCODE(OPCODE_CM_UNK_1833, CM_UNK_1833);
			OPCODE(OPCODE_CM_MOVE, CM_MOVE);
			OPCODE(OPCODE_CM_TARGET, CM_TARGET);
			OPCODE(OPCODE_CM_EMOTION, CM_EMOTION);
			OPCODE(OPCODE_CM_EMOTION2, CM_EMOTION2);
			OPCODE(OPCODE_CM_UNK_2c18, CM_UNK_2c18);
			OPCODE(OPCODE_CM_USE_SKILL, CM_USE_SKILL);
			OPCODE(OPCODE_CM_INVENTORY_MOVE, CM_INVENTORY_MOVE);
			OPCODE(OPCODE_CM_JUMP, CM_JUMP);
			OPCODE(OPCODE_CM_UPDATE_POSITION, CM_UPDATE_POSITION);
			OPCODE(OPCODE_CM_ACTION_STOP, CM_ACTION_STOP);
			OPCODE(OPCODE_CM_MOVE_MOUSESET, CM_MOVE_MOUSESET);
			OPCODE(OPCODE_CM_FLY, CM_FLY);
			OPCODE(OPCODE_CM_REMOVE_ITEM, CM_REMOVE_ITEM);
			OPCODE(OPCODE_CM_USE0, CM_USE0);
			OPCODE(OPCODE_CM_USE, CM_USE);
			OPCODE(OPCODE_CM_USE2, CM_USE2);
			OPCODE(OPCODE_CM_UNK_8c18, CM_UNK_8c18);
			OPCODE(OPCODE_CM_UNK_2913, CM_UNK_2913);

			OPCODE(OPCODE_CM_QUESTLIST, CM_QUESTLIST);
			//		OPCODE(OPCODE_CM_DISCONNECT, CM_DISCONNECT);
			OPCODE(OPCODE_CM_CHAT, CM_CHAT);




		default:
		{
			
			// DEBUG
			memset(bindbg, 0, 2);
			char* fordebug = pck->GetPacketPointer();
			lg::Debug(fg, "C->S: op[%04x][%02x] ", pck->opcode, pck->real_packet_size);
			for (uint16 i = 0; i < (uint16)pck->packet_len; i++)
			{
			if ((uint8)fordebug[i] > 0x20 && (uint8)fordebug[i] <= 'z')
			{
			bindbg[0] = (uint8)fordebug[i];
			lg::Notify(fg, bindbg);
			}
			else
			lg::Notify(fg, ".");
			}
			lg::Notify(fg, "\n");

			lg::Debug(fg, "C->S: op[%04x][%02x] ", pck->opcode, pck->real_packet_size);
			for (uint16 i = 0; i < (uint16)pck->packet_len; i++)
			lg::Notify(fg, "%02x", (uint8)fordebug[i]);

			lg::Notify(fg, "\n");
			// --DEBUG		
		}


		}
		return true;
	}

	inline void opcodes(PACKET* pck, FILE* fg)
	{
		pck->PackCreate();

		if (!LSOpcodes(pck, fg))
		{

		}
	}
};

#endif _OPCODES_H_

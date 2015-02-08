////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _ENUMS_H_
#define _ENUMS_H_

// Character structs
enum eACTION_CHARACTER {
	ACTION_NONE,
	ACTION_GO,
	ACTION_RUN,
	ACTION_JUMP,
	ACTION_FLY,
	ACTION_MINING
};

enum eACCESS_CHARACTER {
	ACCESS_CHARACTER_PLAYER = 0,
	ACCESS_CHARACTER_GAMEMASTER = 1,
	ACCESS_CHARACTER_ADMINISTRATOR = 2
};

enum eCHARACTER_STATUS {
	STATUS_NONE,
	STATUS_CONNECT,
	STATUS_SM_UNK3,
	STATUS_GETAREA,
	STATUS_GETINFO,
	STATUS_DISCONNECT,
	STATUS_CHAT
};

enum ePLAYER_CLASS {
	CLASS_BERSERK = 0,
	CLASS_PRIEST = 1,
	CLASS_WIZARD = 2,
	CLASS_ARCHER = 3,
	CLASS_ASSASSIN = 4,
	CLASS_WARRIOR = 5
};


// Obj structs
enum eOBJ_MOVE {
	OBJMOVE_NOT_MOVE,
	OBJMOVE_RANDOM,
	OBJMOVE_POINTS
};

enum eOBJ_ACTION_STATUS {
	OBJ_ACTION_STAND = 2,
	OBJ_ACTION_MOVE = 5
};

enum sCHATSTATUS
{
	CHAT_SEARCHGROUP = 9,		//Поиск группы
	CHAT_BULLHORN = 8,			//8 Рупор
	CHAT_SHOUT = 7,				//7 - Крик в локации
	CHAT_SYSTEMADVERT = 6,		//6 - Сис сообщение вверху экрана желтым цветом
	CHAT_TRADECHANNEL = 5,		//5 - трейд канал
	CHAT_WHISPERMESSAGE = 4,	//4 - приватное сообщение
	CHAT_GUILDCHANNEL = 3,		//3 - канал гильдии
	CHAT_GROUPCHANNEL = 2,		//2 - группа
	CHAT_WHITEMESSAGE = 1,		//1 - сообщение белым цветом в чате
	CHAT_YELLOWMESSAGE = 0		//0 - сообщение желтым цветом в чате
};
	
#endif




////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _INC_OPCODES_H_
#define _INC_OPCODES_H_

#define OPCODE(p1,p2)		{case p1: p2(pck); break;}

// Server to client
#include "./server/SM_PONG.h"
#include "./server/SM_CONNECT.h"
#include "./server/SM_DISCONNECT.h"
#include "./server/SM_RESTORE_CONNECTION.h"
#include "./server/SM_CHARACTERLIST_RESPONSE.h"
#include "./server/SM_LOBBYUSERMSG.h"
#include "./server/SM_CREATECHARACTER.h"
#include "./server/SM_DELETECHARACTER.h"
#include "./server/SM_STARTGAME.h"
#include "./server/SM_GETPIN.h"
#include "./server/SM_PIN.h"
#include "./server/SM_UPDATE_CHARACTER_INFO.h"
#include "./server/SM_DELETE_S.h"

// Client to server
#include "./client/CM_PING.h"
#include "./client/CM_CONNECT.h"
#include "./client/CM_DISCONNECT.h"
#include "./client/CM_RESTORE_CONNECTION.h"
#include "./client/CM_CHARACTERLIST.h"
#include "./client/CM_CHECKCHARACTERNAME.h"
#include "./client/CM_CREATECHARACTER.h"
#include "./client/CM_DELETECHARACTER.h"
#include "./client/CM_PIN.h"
#include "./client/CM_STARTGAME.h"
#include "./client/CM_UNK1.h"
#include "./client/CM_UNK2.h"

#endif INC_OPCODES_H_



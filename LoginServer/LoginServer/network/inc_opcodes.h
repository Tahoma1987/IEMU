////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _INC_OPCODES_H_
#define _INC_OPCODES_H_

#define OPCODE(p1,p2)		{case p1: p2(pck); break;}

// Server to client
#include "./server/SM_UPDATESERVERINFO.h"
#include "./server/SM_PONG.h"
#include "./server/SM_AUTH.h"
#include "./server/SM_SERVER_LIST.h"
#include "./server/SM_SELECTSERVER.h"

#include "./server/SM_MY_LAUNCHER_LOGIN.h"

// Client to server
#include "./client/CM_AUTH.h"
#include "./client/CM_PING.h"
#include "./client/CM_SERVER_LIST.h"
#include "./client/CM_SELECTSERVER.h"

#include "./client/CM_MY_LAUNCHER_LOGIN.h"




#endif INC_OPCODES_H_



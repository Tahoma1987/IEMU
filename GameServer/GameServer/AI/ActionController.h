////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _ACTION_CONTROLLER_H_
#define _ACTION_CONTROLLER_H_

#include <Windows.h>
#include <stdio.h>
#include <winsock.h>
#include <assert.h>
#include <math.h>

#include "mysql/mysql.h"
#include "../defines.h"
#include "../common/logger.h"
#include "../common/database.h"
#include "../structs.h"
#include "../game_structs.h"
#include "../network/packet.h"
#include "../network/opcodes.h"

class ACTIONCONTROLLER {
public:
	ACTIONCONTROLLER(FILE* fg, DATABASE* mysql, ALL_PLAYERS* players, MOB* mobs, int max_players, int max_spawns);
	~ACTIONCONTROLLER();
	void Frame();

private:
	FILE*				fg;
	MOB*				mobs;
	ALL_PLAYERS*		players;
	int					max_players;
	int					max_spawns;

	void Obj_Actions();

};

#endif _ACTION_CONTROLLER_H_



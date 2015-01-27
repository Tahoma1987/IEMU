////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _DATABASE_H_
#define _DATABASE_H_



#include <winsock.h>
#include "mysql\mysql.h"
#include <stdlib.h>
#include "../defines.h"
#include "logger.h"
#include "../structs.h"
#include "../game_structs.h"

class DATABASE
{

public:
	DATABASE(FILE* fg, char* db_host, char* db_user, char* db_pass, char* db_name);
	~DATABASE();
	bool IsError();

	bool GetCharacterInfo(uint32 character_id, CHARACTER* character);
	bool UpdateCharacterInfo(CHARACTER* character);
	int GetNumMobs();											// получаем количество мобов в БД
	int GetMobs(MOB* mobs);

private:
	MYSQL			mysql;
	MYSQL*			db;
	FILE*			fg;				// handle log file
	bool			error;

	void AtoH(char* in, char* out);

	double mystrtod(char **val){
		char *eptr = NULL, *ptr = *val;
		return strtod(ptr, &eptr);
	}
};


#endif




////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <winsock.h>
#include "mysql\mysql.h"
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

	bool CheckCharname(char* charname);
	int CreateCharacter(char* charname, CHAR_STYLE* st,
						int8 sex, int cls, uint32 account_id);

	int GetCharactersInfo(uint32 account_id, CHARACTER* character_list,
												int max_characters);

	bool GetCharacterName(int charid, char* out);
	int GetNumCharacters(uint32 account_id);
	bool GetPinCode(uint32 account_id, char* out);
	bool SetPinCode(uint32 account_id, char* pin);
	bool UpdatePinCode(uint32 account_id, int errors);
	int GetAccountID(int character_id);

	bool DeleteCharacter(uint32 character_id);


private:
	MYSQL			mysql;
	MYSQL*			db;
	FILE*			fg;
	bool			error;

	void AtoH(char* in, char* out);
};


#endif




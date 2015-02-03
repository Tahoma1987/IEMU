////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#include "database.h"

//=================================================================================
// Create DATABASE class
//
DATABASE::DATABASE(FILE* fg, char* db_host, char* db_user, char* db_pass, char* db_name)
{
	error = false;
	this->fg = fg;
	mysql_init(&mysql);
	db = mysql_real_connect(&mysql,
		    db_host,
		    db_user,
		    db_pass,
		    db_name,
		    0, 0, 0);
	if (db == NULL)
	{
		error = true;
		lg::Notify(fg, "\n");
		lg::Error(fg, "DB connecting failure!\n");
		return;
	}
	mysql_autocommit(db, 1);
}

//=================================================================================
// delete DATABASE class
//
DATABASE::~DATABASE()
{
	mysql_close(&mysql);
}

//=================================================================================
// error in MySQL
//
bool DATABASE::IsError()
{
	return error;
}

//================================================================================
// convert ascii string to hex data
//
void DATABASE::AtoH(char* in, char* out)
{
	int step = 0;
	char tmp[3];
	memset(tmp, 0, 3);

	for (int i = 0; i < (int)strlen(in); i+=2)
	{
		strncpy(tmp, in+i, 2);
		out[step] = (int)strtol(tmp, NULL, 16);
		++step;
	}
}

//================================================================================
// Get character info
//
bool DATABASE::GetCharacterInfo(uint32 character_id, CHARACTER* character)
{
	character_id &= 0xFFFFFFF;
	MYSQL_RES* result;
	MYSQL_ROW row;
	char query[256];
	int sid = 0;
	size_t convertedChars;

	sprintf(query, "SELECT charname, class, level, sex, pos_x, pos_y, pos_z, rotate, access FROM characters WHERE id='%d';", character_id);

	if (mysql_query(db, query))
	{
		lg::Error(fg, "GSDatabase: GetCharacterInfo->mysql_query->characters. %s\n", mysql_error(db));
		return 0;
	}

	result = mysql_store_result(db);
	
	if (result == NULL)
	{
		lg::Error(fg, "GSDatabase: GetCharacterInfo->mysql_store_result->characters. %s\n", mysql_error(db));
		return 0;
	}	

	if ((row = mysql_fetch_row(result)))
	{
		character->id = character_id | 0x80000000;

		convertedChars = 0;
		memset(character->charname, 0, 20);
		mbstowcs_s(&convertedChars, character->charname, strlen(row[0])+1, row[0], _TRUNCATE);
		character->cls = atoi(row[1]);
		character->lvl = atoi(row[2]);
		character->sex = atoi(row[3]);
		if (row[4] != NULL)
			character->pos.pos_x = atof(row[4]);
		if (row[5] != NULL)
			character->pos.pos_y = atof(row[5]);
		if (row[6] != NULL)
			character->pos.pos_z = atof(row[6]);
		if (row[7] != NULL)
			character->pos.rotate = atof(row[7]);

		if (strstr(row[8], "ADMINISTRATOR"))
			character->access = ACCESS_CHARACTER_ADMINISTRATOR;
		else if (strstr(row[8], "GAMEMASTER"))
			character->access = ACCESS_CHARACTER_GAMEMASTER;
		else
			character->access = ACCESS_CHARACTER_PLAYER;

		character->action = ACTION_NONE;
	}
	else
	{
		lg::Error(fg, "GSDatabase: GetCharacterInfo->mysql_fetch_row. %s\n", mysql_error(db));
		mysql_free_result(result);
		return false;
	}

	mysql_free_result(result);

	// Получаем инвентарь
	//////////////////////////////////////////////////////////
	sprintf(query, "SELECT PlayerItemUID, item_id, count, slot, equip FROM inventory WHERE char_id='%d';", character_id);

	if (mysql_query(db, query))
	{
		lg::Error(fg, "GSDatabase: GetCharacterInfo->mysql_query->inventory. %s\n", mysql_error(db));
		return 0;
	}

	result = mysql_store_result(db);

	if (result == NULL)
	{
		lg::Error(fg, "GSDatabase: GetCharacterInfo->mysql_store_result->inventory. %s\n", mysql_error(db));
		return 0;
	}

	while ((row = mysql_fetch_row(result)))
	{
		character->inventory[sid].PlayerItemUID = (int32)atoi(row[0]);
		character->inventory[sid].item_id = (int32)atoi(row[1]);
		character->inventory[sid].count = (int16)atoi(row[2]);
		character->inventory[sid].slot = (int16)atoi(row[3]);
		character->inventory[sid].equip = (int8)atoi(row[4]);
		character->inventory[sid].sid = (int16)sid;
		++sid;
	}
	character->items_in_inventory = sid;
	mysql_free_result(result);

	// Получаем статы
	//////////////////////////////////////////////////////////
	bool error = false;
	sprintf(query, "SELECT max_hp,max_mp,hp,mp,phys_def,magic_def,power,agility,fitness,intelligence,mentality,accuracy FROM character_stats WHERE char_id='%d';", character_id);
	if (mysql_query(db, query))
	{
		lg::Error(fg, "GSDatabase: GetCharacterInfo->mysql_query->character_stats. %s\n", mysql_error(db));
		return 0;
	}
	result = mysql_store_result(db);

	if (result == NULL)
	{
		lg::Error(fg, "GSDatabase: GetCharacterInfo->mysql_store_result->character_stats. %s\n", mysql_error(db));
		return 0;
	}

	if ((row = mysql_fetch_row(result)))
	{
		for (int i = 0; i < 12; i++)
		{
			if (row[i] == NULL)
			{
				error = true;
				break;
			}
		}

		if (!error)
		{
			character->stats.max_hp = atof(row[0]);
			character->stats.max_mp = atof(row[1]);
			character->stats.hp = atof(row[2]);
			character->stats.mp = atof(row[3]);
			character->stats.phys_def = atof(row[4]);
			character->stats.magic_def = atof(row[5]);
			character->stats.power = atof(row[6]);
			character->stats.agility = atof(row[7]);
			character->stats.fitness = atof(row[8]);
			character->stats.intelligence = atof(row[9]);
			character->stats.mentality = atof(row[10]);
			character->stats.accuracy = atof(row[11]);
		}
		else
		{
			lg::Error(fg, "GSDatabase: Can't find character stats. ID: %d\n", character_id);
		}
	}

	mysql_free_result(result);

	// Стиль перса
	//////////////////////////////////////////////////////////
	sprintf(query, "./data/characters/styles/%d.dat", character_id);
	FILE* ftmp = fopen(query, "rb");
	if (ftmp == NULL)
	{
		lg::Error(fg, "GSDatabase: Can't find character style. ID: %d\n", character_id);
		return false;
	}
	fread(&character->style, sizeof(CHAR_STYLE), 1, ftmp);
	fclose(ftmp);

	return true;
}

//================================================================================
// Сохраняем информацию о персонаже в БД
//
bool DATABASE::UpdateCharacterInfo(CHARACTER* character)
{
	MYSQL_RES* result;
	char* query = (char*)malloc(1024 * 2);

	time_t rawTime;
	time(&rawTime);


	sprintf(query, "UPDATE characters SET level=%d, pos_x='%f', pos_y='%f', pos_z='%f', rotate='%f', end_gametime=%d WHERE id = %d;",
		character->lvl,
		character->pos.pos_x,
		character->pos.pos_y,
		character->pos.pos_z,
		character->pos.rotate,
		(int)rawTime,
		character->id & 0x0fffffff
		);

	if (mysql_query(db, query))
	{
		lg::Error(fg, "GSDatabase: UpdateCharacterInfo->mysql_query. %s\n", mysql_error(db));
		free(query);
		return false;
	}

	free(query);
	return true;
}

//================================================================================
// Возвращает количество записей о мобах в БД
//
int DATABASE::GetNumMobs()
{
	MYSQL_RES* result;

	if (mysql_query(db, "SELECT * FROM mobs;"))
	{
		lg::Error(fg, "GSDatabase: GetNumMobs->mysql_query. %s\n", mysql_error(db));
		return 0;
	}

	result = mysql_store_result(db);
	if (result == NULL)
	{
		lg::Error(fg, "GSDatabase: GetNumMobs->mysql_store_result. %s\n", mysql_error(db));
		return 0;
	}

	int num = mysql_num_rows(result);
	if (num)
	{
		mysql_free_result(result);
		return num;
	}

	mysql_free_result(result);
	return 0;
}

//================================================================================
// Записывает информацию о мобах в структуры
//
int DATABASE::GetMobs(MOB* mobs)
{
	MYSQL_RES* result;
	MYSQL_ROW row;

	int step = 0;
	int num_characters = 0;

	const char *query = "SELECT id,		\
							zone,		\
							x,			\
							y,			\
							z,			\
							rotate,		\
							lvl,		\
							type1,		\
							type2,		\
							resp_time,	\
							animation,	\
							unk1,		\
							unk2,		\
							unk3,		\
							unk4,		\
							unk5,		\
							unk6,		\
							unk7,		\
							unk8,		\
							unk21,		\
							unk22,		\
							spawn_id,	\
							unk10,		\
							unk11,		\
							unk12,		\
							unk13,		\
							unk14,		\
							unk15,		\
							unk16,		\
							unk17,		\
							unk18,		\
							unk19,		\
							unk20,		\
							move,		\
							distance	\
							FROM mobs;";

	if (mysql_query(db, query))
	{
		lg::Notify(fg, "\n");
		lg::Error(fg, "GSDatabase: GetMobs->mysql_query. %s\n", mysql_error(db));
		return 0;
	}

	result = mysql_store_result(db);
	if (result == NULL)
	{
		lg::Notify(fg, "\n");
		lg::Error(fg, "GSDatabase: GetMobs->mysql_store_result. %s\n", mysql_error(db));
		return 0;
	}
	
	while ((row = mysql_fetch_row(result)))
	{
		mobs[step].uid = atoi(row[0]);
		mobs[step].zone = atoi(row[1]);
		mobs[step].pos_x = atof(row[2]);
		mobs[step].pos_y = atof(row[3]);
		mobs[step].pos_z = atof(row[4]);
		mobs[step].rotate = atof(row[5]);
		mobs[step].lvl = atoi(row[6]);
		mobs[step].type1 = atoi(row[7]);
		mobs[step].type2 = atoi(row[8]);
		mobs[step].resp_time = atoi(row[9]);
		mobs[step].animation = atoi(row[10]);
		mobs[step].unk1 = atoi(row[11]);
		mobs[step].unk2 = atoi(row[12]);
		mobs[step].unk3 = atoi(row[13]);
		mobs[step].unk4 = atoi(row[14]);
		mobs[step].unk5 = atoi(row[15]);
		mobs[step].unk6 = atoi(row[16]);
		mobs[step].unk7 = atoi(row[17]);
		mobs[step].unk8 = atoi(row[18]);
		mobs[step].unk21 = atoi(row[19]);
		mobs[step].unk22 = atoi(row[20]);
		mobs[step].spawn_id = atoi(row[21]);
		mobs[step].unk10 = atoi(row[22]);
		mobs[step].unk11 = atoi(row[23]);
		mobs[step].unk12 = atoi(row[24]);
		mobs[step].unk13 = atoi(row[25]);
		mobs[step].unk14 = atoi(row[26]);
		mobs[step].unk15 = atoi(row[27]);
		mobs[step].unk16 = atoi(row[28]);
		mobs[step].unk17 = atoi(row[29]);
		mobs[step].unk18 = atoi(row[30]);
		mobs[step].unk19 = atoi(row[31]);
		mobs[step].unk20 = atoi(row[32]);

		if (strstr((row[33]), "NOT_MOVE") != NULL)
			mobs[step].move = OBJMOVE_NOT_MOVE;
		else if (strstr((row[33]), "RANDOM") != NULL)
			mobs[step].move = OBJMOVE_RANDOM;
		else if (strstr((row[33]), "POINTS") != NULL)
			mobs[step].move = OBJMOVE_POINTS;

		mobs[step].move_distance = atoi(row[33]);


		mobs[step].base_pos_x = mobs[step].pos_x;
		mobs[step].base_pos_y = mobs[step].pos_y;
		mobs[step].base_pos_z = mobs[step].pos_z;

		mobs[step].action_status = OBJ_ACTION_STAND; // do not del

		++step;
	}
	mysql_free_result(result);
	return step;
	//sprintf(query, "INSERT INTO mobs VALUES('%d','%d','%f','%f','%f','%f','%d','%d','%d','%d','%d','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%u','%s');",
}
////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <winsock.h>
#include "mysql\mysql.h"
#include "../defines.h"
#include "logger.h"

class DATABASE
{

public:
	DATABASE(FILE* fg, char* db_host, char* db_user, char* db_pass, char* db_name);
	~DATABASE();
	bool IsError();

	bool CheckAccountName(char* password, char* hash);					/* ¬£¬à¬Ù¬Ó¬â¬Ñ¬ë¬Ñ¬Ö¬ä true, ¬Ö¬ã¬Ý¬Ú ¬Ó ¬¢¬¥ ¬ß¬Ñ¬Û¬Õ¬Ö¬ß ¬á¬Ö¬â¬Ö¬Õ¬Ñ¬Ó¬Ñ¬Ö¬Þ¬í¬Û ¬á¬Ñ¬â¬à¬Ý¬î ¬Ú ¬Ù¬Ñ¬á¬Ú¬ã¬í¬Ó¬Ñ¬Ö¬ä ¬ç¬ï¬ê */
	bool GetAccountName(char* hash, char* out, int* id_account);		/* ¬£¬à¬Ù¬Ó¬â¬Ñ¬ë¬Ñ¬Ö¬ä ¬Ý¬à¬Ô¬Ú¬ß, ¬Ö¬ã¬Ý¬Ú ¬Ó ¬¢¬¥ ¬ß¬Ñ¬Û¬Õ¬Ö¬ß ¬á¬Ö¬â¬Ö¬Õ¬Ñ¬Ó¬Ñ¬Ö¬Þ¬í¬Û ¬ç¬ï¬ê */
	int GetServerList(char* buf);										/* ¬£¬à¬Ù¬Ó¬â¬Ñ¬ë¬Ñ¬Ö¬ä ¬è¬Ö¬Ý¬î¬ß¬í¬Û ¬Ò¬å¬æ¬Ö¬â ¬Õ¬Ý¬ñ ¬ã¬ä¬â¬å¬Ü¬ä¬å¬â SERVER_INFO */


private:
	MYSQL			mysql;
	MYSQL*			db;
	FILE*			fg;				// ¬ç¬ï¬ß¬Õ¬Ý ¬Õ¬Ý¬ñ ¬Ý¬à¬Ô¬Ö¬â¬Ñ
	bool			error;
};


#endif




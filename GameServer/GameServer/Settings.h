////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _SETTINGS_H_
#define _SETTINGS_H_

#include <config4cpp\Configuration.h>
using namespace config4cpp;

uint8				id_server;
const char*			name_server;
bool				technical_works;

const char*			gameserver_ip;
int					gameserver_port = 6001;
const char*			inner_ls_ip;
int					inner_ls_port = 5600;
int					refresh_server_info;

// MySQL connect
const char*			db_host;
const char*			db_user;
const char*			db_pass;
const char*			db_name;

int					max_players;					/* max players */
int					max_time_for_disconnect;		// Сколько минут может не отвечать клиент и сервер не разорвет соединение

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

class SETTINGS
{
public:

	Configuration* Init()
	{
		try {
			m_cfg = Configuration::create();
			m_cfg->parse("./configs/GameServer.cfg");
			return m_cfg;
		}
		catch (const ConfigurationException & ex) {
			return NULL;
		}
	}

	void Destroy()
	{
		((Configuration *)m_cfg)->destroy();
	}

private:
	Configuration*	m_cfg;
};


bool LoadSettings(SETTINGS* settings)
{
//	setlocale(LC_ALL, "");
	Configuration* cfg = settings->Init();
	if (cfg == NULL)
		return false;

	id_server = cfg->lookupInt("", "server_id", 253);			// max players
	name_server = cfg->lookupString("", "name_server", "TEST");
	technical_works = cfg->lookupInt("", "technical_works", 1) ? 1 : 0;
	gameserver_ip = cfg->lookupString("", "ip", "127.0.0.1");		// ip address gameserver
	gameserver_port = cfg->lookupInt("", "port", 6001);				// port gameserver

	db_host = cfg->lookupString("", "db_host", "127.0.0.1");
	db_user = cfg->lookupString("", "db_user", "root");
	db_pass = cfg->lookupString("", "db_pass", "password");
	db_name = cfg->lookupString("", "db_name", "ica_gs");

	// inner connect to login server
	inner_ls_ip = cfg->lookupString("", "inner_ls_ip", "127.0.0.1");
	inner_ls_port = cfg->lookupInt("", "inner_ls_port", 5600);
	refresh_server_info = cfg->lookupInt("", "refresh_server_info", 5) * 1000;	// в секундах
	
	max_players = cfg->lookupInt("", "max_players", 1000);			// max players
	max_time_for_disconnect = cfg->lookupInt("", "max_time_for_disconnect", 5) * 1000 * 60;			// max_time_for_disconnect

	return true;
}

#endif _SETTINGS_H_


////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _SETTINGS_H_
#define _SETTINGS_H_

#include <config4cpp\Configuration.h>
using namespace config4cpp;

int					gameserver_id;
const char*			accountserver_ip;// [] = "127.000.000.001";
int					accountserver_port = 5695;
const char*			gameserver_ip;
int					gameserver_port = 6001;
bool				use_pin_code = false;
int					max_characters = 5;

// MySQL connect
const char*			db_host;
const char*			db_user;
const char*			db_pass;
const char*			db_name;

// Inner
const char*			inner_ip;
int					inner_port;


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
class SETTINGS
{
public:

	Configuration* Init()
	{
		try {
			m_cfg = Configuration::create();
			m_cfg->parse("./configs/CharacterServer.cfg");
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

#endif _SETTINGS_H_


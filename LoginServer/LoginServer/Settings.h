////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _SETTINGS_H_
#define _SETTINGS_H_

#include <config4cpp\Configuration.h>
using namespace config4cpp;

const char*			launcher_ip;
int					launcher_port;

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
			m_cfg->parse("./configs/LoginServer.cfg");
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


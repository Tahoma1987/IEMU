////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _SETTINGS_H_
#define _SETTINGS_H_

#include <config4cpp\Configuration.h>
using namespace config4cpp;

const char*			ip;
int					port = 5600;

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
			m_cfg->parse("./configs/InnerServer.cfg");
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
	setlocale(LC_ALL, "");
	Configuration* cfg = settings->Init();
	if (cfg == NULL)
		return false;

	// inner connect
	ip = cfg->lookupString("", "ip", "127.0.0.1");
	port = cfg->lookupInt("", "port", 5600);

	return true;
}

#endif _SETTINGS_H_


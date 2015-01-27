////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _SM_SERVER_LIST_H_
#define _SM_SERVER_LIST_H_

void SM_SERVER_LIST(PACKET* pck)
{
	time_t rawTime;
	time(&rawTime);
	char srv[42];
	WCHAR	wcstring[42];
	size_t convertedChars = 0;
	int num_servers = 0;
	
	for (int i = 0; i < 12; i++)
	{
		if (pck->sockstruct->gameservers_info[i].id != -1)
			++num_servers;
	}

	pck->CreateBufForSend();
	pck->writeD(0);
	pck->writeD(5);
	pck->writeD(num_servers);

	if (num_servers != 0)
	{
		for (int i = 0; i < 12; i++)
		{
			if (pck->sockstruct->gameservers_info[i].id != -1)
			{
				if ((pck->sockstruct->gameservers_info[i].timeupdate + 10 * 60 * 1000) < rawTime)
					continue;

				memset(srv, 0, 42);
				int max_players = pck->sockstruct->gameservers_info[i].players_max;
				int players = pck->sockstruct->gameservers_info[i].players_connected;				
				memset(wcstring, 0, sizeof(wcstring) - 1);
				mbstowcs_s(&convertedChars, wcstring, strlen(pck->sockstruct->gameservers_info[i].name) + 1, pck->sockstruct->gameservers_info[i].name, _TRUNCATE);
				memcpy(srv, wcstring, convertedChars * 2);

				pck->writeD(pck->sockstruct->gameservers_info[i].id);
				pck->writeBuf(srv, 42);
				pck->writeW(1); // unk
				pck->writeD(1); // unk


				pck->writeD(2);
/*				if ((max_players / 4 * 1) > players) {
					pck->writeD(0);
				}
				else if ((max_players / 4 * 2) < players) {
					pck->writeD(1);
				}
				else if ((max_players / 4 * 3) < players) {
					pck->writeD(2);
				}
				else {
					pck->writeD(3);
				}*/

				pck->writeB(0);
				pck->writeB(0);
				pck->writeW(0);
			}
		}

	}
	pck->PackSend(OPCODE_SM_SERVER_LIST);
	pck->sockstruct->send_serverlist = true;
}

#endif




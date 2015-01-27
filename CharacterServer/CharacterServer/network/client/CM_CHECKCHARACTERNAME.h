////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_CHECKCHARACTERNAME_H_
#define _CM_CHECKCHARACTERNAME_H_

void CM_CHECKCHARACTERNAME(PACKET* pck)
{
	char charname[18];
	WCHAR w_charname[18];
	int len_w_charname = pck->readWstr(w_charname);
	int len_charname = wcstombs(charname, w_charname, 18);

	if (len_charname < 4 || len_charname > 16)
	{
		SM_LOBBYUSERMSG(pck, 14);					// ¬Ü¬à¬Ý¬Ú¬é¬Ö¬ã¬ä¬Ó¬à ¬ã¬Ú¬Þ¬Ó¬à¬Ý¬à¬Ó ¬Ó charname ¬ß¬Ö¬Õ¬à¬á¬å¬ã¬ä¬Ú¬Þ¬à
		return;
	}

	if (!(pck->sql->CheckCharname(charname)))
	{
		SM_LOBBYUSERMSG(pck, 14);
		return;
	}

	SM_LOBBYUSERMSG(pck, 0);
	
}

#endif
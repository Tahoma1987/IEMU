////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////


#include "stdafx.h"
#include "Main.h"


int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	hInst = hInstance; // Store instance handle in our global variable
	DialogBox(hInst, MAKEINTRESOURCE(IDD_MAIN), NULL, WndProc);
	return 0;

}



void GetMD5(char* in, char* out)
{
	char* result = new char[1024];
	memset(result, 0, 1024);
	MD5((unsigned char*)in, strlen(in), (unsigned char*)result);
	sprintf(out, "%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x",
		(uint8)result[0], (uint8)result[1], (uint8)result[2], (uint8)result[3], (uint8)result[4], (uint8)result[5], (uint8)result[6], (uint8)result[7],
		(uint8)result[8], (uint8)result[9], (uint8)result[10], (uint8)result[11], (uint8)result[12], (uint8)result[13], (uint8)result[14], (uint8)result[15]);
	delete (result);
}

bool CheckAccount()
{
	char login[32];
	char md5_login[64];
	char password[32];
	char md5_password[64];
	
	memset(md5_hash, 0, sizeof(md5_hash));

	SendMessage(hLogin, WM_GETTEXT, (WPARAM)32, (LPARAM)login);
	SendMessage(hPassword, WM_GETTEXT, (WPARAM)32, (LPARAM)password);

	GetMD5(login, md5_login);
	GetMD5(password, md5_password);
	memset(login, 0, sizeof(login));
	memset(password, 0, sizeof(password));

	sprintf(md5_hash, "%s%s", md5_login, md5_password);
		return true;
}

bool StartGame()
{
	int tt = strlen(md5_hash);
	char packet[1024];
	int packet_len = strlen(md5_hash) + 6 +1;
	memcpy(packet + 6, md5_hash, strlen(md5_hash));
	*(WORD *)(packet + 0) = packet_len;
	*(WORD *)(packet + 2) = 0xfeff;
	*(WORD *)(packet + 4) = 0x0000;
	packet[packet_len-1] = 0;

	WORD ver = MAKEWORD(2, 2);
	WSADATA wsaData;
	int retVal = 0;

	WSAStartup(ver, (LPWSADATA)&wsaData);

	LPHOSTENT hostEnt;

	hostEnt = gethostbyname(loginserver_ip);

	if (!hostEnt)
	{
		MessageBox(hMainWND, "Unable to collect gethostbyname", "ERROR", MB_OK | MB_ICONERROR);
		WSACleanup();
		return false;
	}

	//¬³¬à¬Ù¬Õ¬Ñ¬Ö¬Þ ¬ã¬à¬Ü¬Ö¬ä
	SOCKET clientSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (clientSock == SOCKET_ERROR)
	{
		MessageBox(hMainWND, "Unable to create socket", "ERROR", MB_OK | MB_ICONERROR);
		WSACleanup();
		return false;
	}

	SOCKADDR_IN serverInfo;

	serverInfo.sin_family = PF_INET;
	serverInfo.sin_addr = *((LPIN_ADDR)*hostEnt->h_addr_list);
	serverInfo.sin_port = htons(loginserver_port);

	retVal = connect(clientSock, (LPSOCKADDR)&serverInfo, sizeof(serverInfo));
	if (retVal == SOCKET_ERROR)
	{

		MessageBox(hMainWND, "Unable to connect", "ERROR", MB_OK | MB_ICONERROR);
		WSACleanup();
		return false;
	}

	retVal = send(clientSock, packet, packet_len, 0);

	if (retVal == SOCKET_ERROR)
	{
		MessageBox(hMainWND, "Unable to send", "ERROR", MB_OK | MB_ICONERROR);
		WSACleanup();
		return false;
	}

	char szResponse[1024];
	retVal = recv(clientSock, szResponse, 1024, 0);

	if (retVal == SOCKET_ERROR)
	{
		MessageBox(hMainWND, "Unable to recv", "ERROR", MB_OK | MB_ICONERROR);
		WSACleanup();
		return false;
	}

//	closesocket(clientSock);
	WSACleanup();

	if (strlen(szResponse+6) > 30)
	{
		sprintf(startparam, "/i:%s /r:2621993 /O /u:5223139 /m:P", szResponse + 6);
		return true;
	}
	else
	{
		MessageBox(hMainWND, "Account not found", "ERROR", MB_OK | MB_ICONERROR);
	}
	return false;
}


INT_PTR CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId;

	switch (message)
	{
	case WM_INITDIALOG:
		hMainWND = hWnd;
		hLogin = GetDlgItem(hWnd, IDC_LOGIN);
		hPassword = GetDlgItem(hWnd, IDC_PASSWORD);
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		wmId = LOWORD(wParam);
		if (wmId == IDB_START)
		{
			CheckAccount();
			if (StartGame())
			{ 
				// start game
				SetCurrentDirectory("./Bin32");
				ShellExecute(NULL, "open", "Icarus.exe", startparam, NULL, SW_NORMAL);
				Sleep(100);
				EndDialog(hWnd, LOWORD(wParam));
			}
		}
		break;

	case WM_CLOSE:
		EndDialog(hWnd, LOWORD(wParam));
		return (INT_PTR)TRUE;
	}
	return (INT_PTR)FALSE;
}


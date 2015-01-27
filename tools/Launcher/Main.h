////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#pragma once

#include "resource.h"
#include "openssl\md5.h"

#define uint8 unsigned __int8 

HINSTANCE hInst;								// current instance

HWND		hMainWND;
HWND		hLogin;
HWND		hPassword;
char		md5_hash[128];

char		loginserver_ip[] = "127.0.0.1";
int			loginserver_port = 5694;
char		startparam[1024];


INT_PTR CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
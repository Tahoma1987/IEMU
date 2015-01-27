////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _DEFINES_H_
#define _DEFINES_H_

#define uint64		unsigned __int64
#define uint32		unsigned int
#define uint16		unsigned __int16
#define uint8		unsigned __int8

#define int64		__int64
#define int32		__int32
#define int16		__int16
#define int8		__int8

#define ENABLE_CONSOLE_COLOR

#ifdef ENABLE_CONSOLE_COLOR
#define COLOR_BL	SetConsoleTextAttribute(hConsole, (WORD)FOREGROUND_BLUE | FOREGROUND_INTENSITY);
#define COLOR_RL	SetConsoleTextAttribute(hConsole, (WORD)FOREGROUND_RED | FOREGROUND_INTENSITY);
#define COLOR_RB	SetConsoleTextAttribute(hConsole, (WORD)FOREGROUND_BLUE | FOREGROUND_RED);
#define COLOR_GL	SetConsoleTextAttribute(hConsole, (WORD)FOREGROUND_GREEN | FOREGROUND_INTENSITY);
#define COLOR_RGBL	SetConsoleTextAttribute(hConsole, (WORD)FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
#else
#endif

#endif _DEFINES_H_
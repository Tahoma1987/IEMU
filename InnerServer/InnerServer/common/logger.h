////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _LOGGER_H
#define _LOGGER_H

#include <stdarg.h>
#include <stdio.h>
#include <time.h>

namespace log
{
   inline FILE* Init()
   {
      time_t rawTime;
      time(&rawTime);
      tm* timeinfo = localtime(&rawTime);
      int8 tmp[128];
	  CreateDirectory("./logs", NULL);
      sprintf(tmp, "./logs/inner_%d%02i%02i.log",  timeinfo->tm_year+1900, timeinfo->tm_mon+1, timeinfo->tm_mday);
      FILE* flog = fopen(tmp, "a+");
      if (flog == NULL)
        return NULL;
	  return flog;
   }
    
   inline void GetTime(char* str)
   {
      time_t rawTime;
      time(&rawTime);
      tm* timeinfo = localtime(&rawTime);
      sprintf(str, "%02i:%02i:%02i ",  timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
   }
   
   inline void Info(FILE* fg, const int8* format, ...)
   {
	   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	   COLOR_RGBL
      va_list ap;
      va_start(ap, format);
      
      char* tm = new char[16];
      GetTime(tm);
      printf(tm);
      printf("[INFO] ");
      vprintf(format, ap);
      fprintf(fg, tm);
      fprintf(fg, "[INFO] ");
      vfprintf(fg, format, ap);
      fflush(fg);
      delete(tm);
   }
   
   inline void Warn(FILE* fg, const int8* format, ...)
   {
	  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	  COLOR_BL
      va_list ap;
      va_start(ap, format);
      
      char* tm = new char[16];
      GetTime(tm);
      printf(tm);
      printf("[WARN] ");
      vprintf(format, ap);
      fprintf(fg, tm);
      fprintf(fg, "[WARN] ");
      vfprintf(fg, format, ap);
      fflush(fg);
      delete(tm);
   }
   
   inline void Error(FILE* fg, const int8* format, ...)
   {
	  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	  COLOR_RL
      va_list ap;
      va_start(ap, format);
      
      char* tm = new char[16];
      GetTime(tm);
      printf(tm);
      printf("[ERROR] ");
      vprintf(format, ap);
      fprintf(fg, tm);
      fprintf(fg, "[ERROR] ");
      vfprintf(fg, format, ap);
      fflush(fg);
      delete(tm);
   }

   inline void Debug(FILE* fg, const int8* format, ...)
   {
	   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	   COLOR_RB
	   va_list ap;
	   va_start(ap, format);

	   char* tm = new char[16];
	   GetTime(tm);
	   printf(tm);
	   printf("[DEBUG] ");
	   vprintf(format, ap);
	   fprintf(fg, tm);
	   fprintf(fg, "[DEBUG] ");
	   vfprintf(fg, format, ap);
	   fflush(fg);
	   delete(tm);
   }
   
   inline void Notify(FILE* fg, const int8* format, ...)
   {
      va_list ap;
      va_start(ap, format);      
      vprintf(format, ap);
      vfprintf(fg, format, ap);
      fflush(fg);
   }
};

#endif


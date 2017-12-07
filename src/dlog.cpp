#include <cstdio>
#include <cstdarg>
#include <cstdlib>
#include "dlog.h"

//[DllImportAttribute(Libraries.Dlog, EntryPoint = "dlog_print", CallingConvention = CallingConvention.Cdecl)]
//internal static extern int Print(LogPriority prio, string tag, string fmt, string msg);

//[DllImportAttribute(Libraries.Dlog, EntryPoint = "dlog_print", CallingConvention = CallingConvention.Cdecl)]
//internal static extern int Print(LogPriority prio, string tag, string fmt, string file, string func, int line, string msg);

extern "C" {

int dlog_print( log_priority prio, const char *tag, const char *fmt, ... )
{
  va_list arg;
  va_start(arg, fmt);
  int numChars = 0;

  char *format = NULL;
  if(asprintf(&format, "%s:\e[21m %s: %s\e[0m", prio==DLOG_INFO?"\e[1;34mINFO":prio==DLOG_WARN?"\e[1;33mWARN":prio==DLOG_ERROR?"\e[1;91mERROR":"", tag, fmt))
  {
    numChars = vfprintf(stderr, format, arg);
    free(format);
  }
  va_end(arg);
  return numChars;
}


}

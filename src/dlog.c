/*
 * Copyright (c) 2017 Samsung Electronics Co., Ltd All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the License);
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "dlog.h"

#ifdef WIN32
#include "asprintf.h"
#endif

int dlog_print_internal( log_priority prio, const char *tag, const char *fmt, va_list arg )
{
  int numChars = 0;
  char *message = NULL;
  int messageLength = vasprintf(&message, fmt, arg);
  if(messageLength > 0)
  {
    // Append line feed if message is not end with line feed.
    char lineFeed[2] = {'\0', '\0'};
    if(message[messageLength-1] != '\n')
    {
      lineFeed[0] = '\n';
    }

    numChars = fprintf(stderr, "%s:\e[21m %s: %s%s\e[0m", prio==DLOG_DEBUG?"\e[1;37mDEBUG":prio==DLOG_INFO?"\e[1;34mINFO":prio==DLOG_WARN?"\e[1;33mWARN":prio==DLOG_ERROR?"\e[1;91mERROR":"", tag, message, lineFeed);
    free(message);
  }
  return numChars;
}

int dlog_print( log_priority prio, const char *tag, const char *fmt, ... )
{
  va_list arg;
  va_start(arg, fmt);

  int numChars = dlog_print_internal(prio, tag, fmt, arg);

  va_end(arg);
  return numChars;
}

int dlog_print_dotnet( log_priority prio, const char *tag, const char *fmt, ... )
{
  va_list arg;
  va_start(arg, fmt);

  int numChars = dlog_print_internal(prio, tag, fmt, arg);

  va_end(arg);
  return numChars;
}

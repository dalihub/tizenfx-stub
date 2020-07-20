#pragma once

#include <stdarg.h>
#include "config.h"

#ifdef HAVE_WINDOWS_H
#include <windows.h>
#endif

#ifdef HAVE_COMBASEAPI_H
#include <combaseapi.h>
#endif

#ifndef HAVE_VASPRINTF
int vasprintf(char **strp, const char *format, va_list ap);
#endif

#ifndef HAVE_ASPRINTF
int asprintf(char **strp, const char *format, ...);
#endif

#ifdef _WIN32
char *co_strdup(const char *p);

/* Interopable functions with .NET Core */
#define malloc CoTaskMemAlloc
#define free CoTaskMemFree
#define realloc CoTaskMemRealloc
#define strdup co_strdup
#endif

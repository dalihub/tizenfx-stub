/*
 * Copyright (c) 2021 Samsung Electronics Co., Ltd All Rights Reserved
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

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <tizen_error.h>

enum InformationError
{
	None = TIZEN_ERROR_NONE,
	InvalidParameter = TIZEN_ERROR_INVALID_PARAMETER,
	OutOfMemory = TIZEN_ERROR_OUT_OF_MEMORY,
	Io = TIZEN_ERROR_IO_ERROR,
	RemoteIo = TIZEN_ERROR_REMOTE_IO,
	PermissionDenied = TIZEN_ERROR_PERMISSION_DENIED,
	NotSupported = TIZEN_ERROR_NOT_SUPPORTED,
	NoData = TIZEN_ERROR_NO_DATA
};

typedef enum {
	SYSTEM_INFO_TYPE_MIN = 0,
	SYSTEM_INFO_BOOL = SYSTEM_INFO_TYPE_MIN,
	SYSTEM_INFO_INT,
	SYSTEM_INFO_DOUBLE,
	SYSTEM_INFO_STRING,
	SYSTEM_INFO_TYPE_MAX,
} system_info_type_e;

int system_info_get_platform_type(const char *key, system_info_type_e *type)
{
  if(strcmp(key, "http://tizen.org/feature/opengles.surfaceless_context") == 0)
  {
	*type = SYSTEM_INFO_BOOL;
  }
  if(strcmp(key, "http://tizen.org/feature/screen.width") == 0)
  {
	*type = SYSTEM_INFO_INT;
  }
  if(strcmp(key, "http://tizen.org/feature/screen.height") == 0)
  {
	*type = SYSTEM_INFO_INT;
  }
  return (int)(None);
}

int system_info_get_custom_type(const char *key, system_info_type_e *type)
{
  return (int)(None);
}

int system_info_get_platform_bool(const char *key, bool *value)
{
  if(strcmp(key, "http://tizen.org/feature/opengles.surfaceless_context") == 0)
  {
	*value = true; // Support surfaceless context
  }
  return (int)(None);
}

int system_info_get_platform_int(const char *key, int *value)
{
  if(strcmp(key, "http://tizen.org/feature/screen.width") == 0)
  {
	*value = 1280;
  }
  if(strcmp(key, "http://tizen.org/feature/screen.height") == 0)
  {
	*value = 720;
  }
  return (int)(None);
}
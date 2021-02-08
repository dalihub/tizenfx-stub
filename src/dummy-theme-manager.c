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

const int ErrorNone = 0;
const int ErrorInvalidParameter = -22;
const int ErrorPermissionDenied =-13;
const int ErrorIoError = -5;
const int ErrorNoSuchTheme =-2;
const int ErrorKeyNotAvailable = -126;

int theme_get_id(void* handle, char** id)
{
  id = 0;
  return ErrorNone;
}

int theme_get_version(void* handle, char** version)
{
  return ErrorNone;
}

int theme_get_tool_version(void* handle, char** version)
{
  return ErrorNone;
}

int theme_get_title(void* handle, char** title)
{
  return ErrorNone;
}

int theme_get_resolution(void* handle, char** resolution)
{
  return ErrorNone;
}

int theme_get_preview(void* handle, char** preview)
{
  return ErrorNone;
}

int theme_get_description(void* handle, char** description)
{
  return ErrorNone;
}

int theme_get_string(void* handle, char* key, char** val)
{
  return ErrorNone;
}

int theme_get_string_array(void* handle, char* key, void** val, int* count)
{
  return ErrorNone;
}

int theme_get_path(void* handle, char* key, char** val)
{
  return ErrorNone;
}

int theme_get_path_array(void* handle, char* key, void** val, int* count)
{
  return ErrorNone;
}

int theme_get_int(void* handle, char* key, int* val)
{
  return ErrorNone;
}

int theme_get_float(void* handle, char* key, float* val)
{
  return ErrorNone;
}

int theme_get_bool(void* handle, char* key, bool* val)
{
  return ErrorNone;
}

int theme_is_key_exist(void* handle, char* key, bool* val)
{
  return ErrorNone;
}

int theme_clone(void* handle, void** cloned)
{
  return ErrorNone;
}

int theme_destroy(void* handle)
{
  return ErrorNone;
}

int theme_loader_create(void** loaderHandle)
{
  return ErrorNone;
}

int theme_loader_destroy(void* loaderHandle)
{
  return ErrorNone;
}

typedef void (* ThemeLoaderChangedCallback)(void*, void*);

int theme_loader_add_event(void* loaderHandle, ThemeLoaderChangedCallback callback, void* userData, char** eventId)
{
  return ErrorNone;
}

int theme_loader_remove_event(void* loaderHandle, char* eventId)
{
  return ErrorNone;
}

int theme_loader_load_current(void* loaderHandle, void** handle)
{
  return ErrorNone;
}

int theme_loader_load(void* loaderHandle, char* id, void** handle)
{
  return ErrorNone;
}

int theme_loader_query_id(void* loaderHandle, void** ids, int* count)
{
  return ErrorNone;
}

int theme_loader_set_current(void* loaderHandle, char* id)
{
  return ErrorNone;
}
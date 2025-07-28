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
#ifndef WIN32
#include <linux/limits.h>
#endif

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <tizen_error.h>

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#ifdef WIN32
#include "asprintf.h"
#endif

/**
 * @brief Enumeration for Preference Error.
 * @since_tizen 2.3
 */
typedef enum {
	PREFERENCE_ERROR_NONE = TIZEN_ERROR_NONE, /**< Successful */
	PREFERENCE_ERROR_INVALID_PARAMETER = TIZEN_ERROR_INVALID_PARAMETER, /**< Invalid parameter */
	PREFERENCE_ERROR_OUT_OF_MEMORY = TIZEN_ERROR_OUT_OF_MEMORY, /**< Out of memory */
	PREFERENCE_ERROR_NO_KEY = TIZEN_ERROR_APPLICATION | 0x30, /**< Required key not available */
	PREFERENCE_ERROR_IO_ERROR = TIZEN_ERROR_IO_ERROR , /**< Internal I/O Error */
} preference_error_e;

/**
 * @brief Enumeration for Preference type.
 * @since_tizen 5.5
 */
typedef enum {
	PREFERENCE_TYPE_NONE = 0, /**< None */
	PREFERENCE_TYPE_STRING, /**< String */
	PREFERENCE_TYPE_INT, /**< Int */
	PREFERENCE_TYPE_DOUBLE, /**< Double */
	PREFERENCE_TYPE_BOOLEAN, /**< Bool */
} preference_type_e;

typedef void (*preference_changed_cb) (const char *key, void *user_data);

typedef bool (*preference_item_cb)(const char *key, void *user_data);

int preference_set_int(const char *key, int value)
{
  return PREFERENCE_ERROR_NONE;
}


int preference_get_int(const char *key, int *value)
{
  return PREFERENCE_ERROR_NONE;
}

int preference_set_double(const char *key, double value)
{
  return PREFERENCE_ERROR_NONE;
}

int preference_get_double(const char *key, double *value)
{
  return PREFERENCE_ERROR_NONE;
}
int preference_set_string(const char *key, const char *value)
{
  return PREFERENCE_ERROR_NONE;
}

int preference_get_string(const char *key, char **value)
{
  return PREFERENCE_ERROR_NONE;
}

int preference_set_boolean(const char *key, bool value)
{
  return PREFERENCE_ERROR_NONE;
}

int preference_get_boolean(const char *key, bool *value)
{
  return PREFERENCE_ERROR_NONE;
}

int preference_remove(const char *key)
{
  return PREFERENCE_ERROR_NONE;
}

int preference_is_existing(const char *key, bool *existing)
{
  // Always return false for test.
  *existing = false;
  return PREFERENCE_ERROR_NONE;
}

int preference_remove_all(void)
{
  return PREFERENCE_ERROR_NONE;
}

int preference_set_changed_cb(const char *key, preference_changed_cb callback, void *user_data)
{
  return PREFERENCE_ERROR_NONE;
}

int preference_unset_changed_cb(const char *key)
{
  return PREFERENCE_ERROR_NONE;
}

int preference_foreach_item(preference_item_cb callback, void *user_data)
{
  return PREFERENCE_ERROR_NONE;
}

int preference_get_type(const char *key, preference_type_e *type)
{
  *type = PREFERENCE_TYPE_NONE;
  return PREFERENCE_ERROR_NONE;
}

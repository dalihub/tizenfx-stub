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


#include <inttypes.h>

int32_t i18n_ulocale_canonicalize(const char *locale_id, char *name, int32_t name_capacity)
{
  return -1;
}

int i18n_ulocale_get_language(const char *locale_id, char *language, int32_t language_capacity, int32_t *buf_size_language)
{
  return -1;
}

int32_t i18n_ulocale_get_script(const char *locale_id, char *script, int32_t script_capacity)
{
  return -1;
}

int32_t i18n_ulocale_get_country(const char *locale_id, char *country, int32_t country_capacity, int *error)
{
  return -1;
}

int32_t i18n_ulocale_get_variant(const char *locale_id, char *variant, int32_t variant_capacity)
{
  return -1;
}

uint32_t i18n_ulocale_get_lcid(const char *locale_id)
{
  return 0;
}

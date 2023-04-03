/*
 * Copyright (c) 2023 Samsung Electronics Co., Ltd All Rights Reserved
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

#ifndef __THEME_COMMON_H__
#define __THEME_COMMON_H__

#define THEME_COUNT 2

const char* ThemeId[THEME_COUNT] = { "org.tizen.default-light-theme", "org.tizen.default-dark-theme" };
const char* ThemeTitle[THEME_COUNT] = { "Light Theme", "Dark Theme" };
int CurrentThemeIndex = 0;

#endif // __THEME_COMMON_H__

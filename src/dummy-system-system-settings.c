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

const int SYSTEM_SETTINGS_ERROR_NONE = 0;

/**
 * @brief Enumeration for System Settings Key.
 * @since_tizen 2.3
 */
typedef enum {
	SYSTEM_SETTINGS_KEY_INCOMING_CALL_RINGTONE, /**< (string) The file path of the current ringtone */
	SYSTEM_SETTINGS_KEY_WALLPAPER_HOME_SCREEN, /**< (string) The file path of the current home screen wallpaper */
	SYSTEM_SETTINGS_KEY_WALLPAPER_LOCK_SCREEN, /**< (string) The file path of the current lock screen wallpaper */
	SYSTEM_SETTINGS_KEY_FONT_SIZE, /**< (int) The current system font size */
	SYSTEM_SETTINGS_KEY_FONT_TYPE, /**< (string) The current system font type */
	SYSTEM_SETTINGS_KEY_MOTION_ACTIVATION, /**< (bool) Indicates whether the motion service is activated */
	SYSTEM_SETTINGS_KEY_EMAIL_ALERT_RINGTONE,  /**< (string) The file path of the current email alert ringtone */
	SYSTEM_SETTINGS_KEY_USB_DEBUGGING_ENABLED,	/**< (bool) Indicates whether the USB debugging is enabled (Since @if MOBILE 2.4 @elseif WEARABLE 3.0 @endif) */
	SYSTEM_SETTINGS_KEY_3G_DATA_NETWORK_ENABLED,  /**< (bool) Indicates whether the 3G data network is enabled (Since @if MOBILE 2.4 @elseif WEARABLE 3.0 @endif) */
	SYSTEM_SETTINGS_KEY_LOCKSCREEN_APP = SYSTEM_SETTINGS_KEY_3G_DATA_NETWORK_ENABLED+2,	 /**< (string) Indicates lockscreen app pkg name  */
	SYSTEM_SETTINGS_KEY_DEFAULT_FONT_TYPE,/**< (string) The current system default font type (only support Get) */
	SYSTEM_SETTINGS_KEY_LOCALE_COUNTRY,		/**< (string) Indicates the current country setting in the <LANGUAGE>_<REGION> syntax. The country setting is in the ISO 639-2 format, and the region setting is in the ISO 3166-1 alpha-2 format */
	SYSTEM_SETTINGS_KEY_LOCALE_LANGUAGE,	/**< (string) Indicates the current language setting in the <LANGUAGE>_<REGION> syntax. The language setting is in the ISO 639-2 format and the region setting is in the ISO 3166-1 alpha-2 format. */
	SYSTEM_SETTINGS_KEY_LOCALE_TIMEFORMAT_24HOUR,	/**< (bool) Indicates whether the 24-hour clock is used. If the value is @c false, the 12-hour clock is used. */
	SYSTEM_SETTINGS_KEY_LOCALE_TIMEZONE,	/**< (string) Indicates the current time zone. */
	SYSTEM_SETTINGS_KEY_TIME_CHANGED,		/**< (int) Once System changes time, this event occurs to notify time change. */
	SYSTEM_SETTINGS_KEY_SOUND_LOCK,					/**< GET (bool) Indicates whether the screen lock sound is enabled on the device. ex) LCD on/off sound */
	SYSTEM_SETTINGS_KEY_SOUND_SILENT_MODE,			/**< GET (bool) Indicates whether the device is in the silent mode. */
	SYSTEM_SETTINGS_KEY_SOUND_TOUCH,				/**< GET (bool) Indicates whether the screen touch sound is enabled on the device. */
	SYSTEM_SETTINGS_KEY_DISPLAY_SCREEN_ROTATION_AUTO,	/**< GET (bool) Indicates whether rotation control is automatic.*/
	SYSTEM_SETTINGS_KEY_DEVICE_NAME,					/**< GET (string) Indicates device name. */
	SYSTEM_SETTINGS_KEY_MOTION_ENABLED,					/**< GET (bool) Indicates whether the device user has enabled the motion feature. */
	SYSTEM_SETTINGS_KEY_NETWORK_WIFI_NOTIFICATION,		/**< GET (bool) Indicates whether Wi-Fi-related notifications are enabled on the device. */
	SYSTEM_SETTINGS_KEY_NETWORK_FLIGHT_MODE,			/**< GET (bool) Indicates whether the device is in the flight mode. */
	SYSTEM_SETTINGS_KEY_SCREEN_BACKLIGHT_TIME,			/**< (int) Indicates the backlight time (in seconds). @internal The following values can be used: 15, 30, 60, 120, 300, and 600. */
	SYSTEM_SETTINGS_KEY_SOUND_NOTIFICATION,				/**< (string) Indicates the file path of the current notification tone set by the user. */
	SYSTEM_SETTINGS_KEY_SOUND_NOTIFICATION_REPETITION_PERIOD,	/**< (int) Indicates the time period for notification repetitions. */
	SYSTEM_SETTINGS_KEY_LOCK_STATE,		/**< (int) Indicates the current lock state */
	SYSTEM_SETTINGS_KEY_ADS_ID, /**< (string) Indicates Ads ID for each device (Since 3.0) */
	SYSTEM_SETTINGS_KEY_ULTRA_DATA_SAVE, /**< (int) Indicates Ultra Data Save status, one of #system_settings_uds_state_e values (Since 4.0) */
	SYSTEM_SETTINGS_KEY_ULTRA_DATA_SAVE_PKG_LIST, /**< (string) Indicates Ultra Data Save Package List (Since 4.0), the list is a string containing whitelisted package names separated with semicolons (;) */
	SYSTEM_SETTINGS_KEY_ACCESSIBILITY_TTS,				/**< GET (bool) Indicates whether the accessibility TTS is enabled on the device. (Since 4.0) */
	SYSTEM_SETTINGS_KEY_VIBRATION,				/**< (bool) Indicates whether vibration is enabled on the device. (Since 4.0) */
	SYSTEM_SETTINGS_KEY_MAX,
} system_settings_key_e;

/**
 * @brief Called when the system settings changes.
 * @since_tizen 2.3
 * @param[in] key The key name of the system settings changed system settings
 * @param[in] user_data The user data passed from the callback registration function
 * @pre system_settings_set_changed_cb() will invoke this callback function.
 * @see system_settings_set_changed_cb()
 * @see system_settings_unset_changed_cb()
 */
typedef void (*system_settings_changed_cb)(system_settings_key_e key, void *user_data);

int system_settings_add_changed_cb(system_settings_key_e key, system_settings_changed_cb callback, void *user_data)
{
  return SYSTEM_SETTINGS_ERROR_NONE;
}

int system_settings_remove_changed_cb(system_settings_key_e key, system_settings_changed_cb callback, void *user_data)
{
  return SYSTEM_SETTINGS_ERROR_NONE;
}

int system_settings_get_value_int(system_settings_key_e key, int *value)
{
  if(key == SYSTEM_SETTINGS_KEY_FONT_SIZE)
  {
    *value = 1; // FontSize normal
  }
  return SYSTEM_SETTINGS_ERROR_NONE;
}
int system_settings_get_value_bool(system_settings_key_e key, bool *value)
{
  return SYSTEM_SETTINGS_ERROR_NONE;
}
int system_settings_get_value_string(system_settings_key_e key, char **value)
{
  if(key == SYSTEM_SETTINGS_KEY_FONT_TYPE)
  {
	*value = malloc(sizeof(char) * 11);
	strncpy(*value, "BreezeSans", 11);
  }
  return SYSTEM_SETTINGS_ERROR_NONE;
}
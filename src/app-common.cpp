#include <stdio.h>
#include <linux/limits.h>

#define TIZEN_PATH_MAX PATH_MAX
const int APP_ERROR_NONE=0;

typedef enum {
  APP_EVENT_LOW_MEMORY, /**< The low memory event */
  APP_EVENT_LOW_BATTERY, /**< The low battery event */
  APP_EVENT_LANGUAGE_CHANGED, /**< The system language changed event */
  APP_EVENT_DEVICE_ORIENTATION_CHANGED, /**< The device orientation changed event */
  APP_EVENT_REGION_FORMAT_CHANGED, /**< The region format changed event */
  APP_EVENT_SUSPENDED_STATE_CHANGED, /**< The suspended state changed event of the application*/
  APP_EVENT_UPDATE_REQUESTED, /**< The update requested event (Since 3.0)*/
} app_event_type_e;

// [DllImport(Libraries.AppCommon, EntryPoint = "app_get_id")]
// internal static extern ErrorCode AppGetId(out string appId);
int app_get_id(char **id)
{
  static char id_buf[TIZEN_PATH_MAX] = {'A','p','p','\0'};

  if( id != NULL )
  {
    *id = strdup(id_buf);
    return APP_ERROR_NONE;
  }
  return APP_ERROR_INVALID_PARAMETER;
}

// [DllImport(Libraries.AppCommon, EntryPoint = "app_get_name")]
// internal static extern ErrorCode AppGetName(out string name);
int app_get_name(char **name)
{
  static char namebuf[TIZEN_PATH_MAX] = {'A','p','p','\0'};
  if( name != NULL )
  {
    *name = strdup(namebuf);
  }
  return APP_ERROR_INVALID_PARAMETER;
}

// [DllImport(Libraries.AppCommon, EntryPoint = "app_get_resource_path")]
// internal static extern string AppGetResourcePath();
char* app_get_resource_path(void)
{
  const char* path=getenv("DESKTOP_PREFIX");
  char* out;
  int numChars = asprintf( &out, "%s/share/app", path );
  return out;
}

// [DllImport(Libraries.AppCommon, EntryPoint = "app_get_data_path")]
// internal static extern string AppGetDataPath();
char* app_get_data_path(void)
{
  return app_get_resource_path();
}

// [DllImport(Libraries.AppCommon, EntryPoint = "app_get_cache_path")]
// internal static extern string AppGetCachePath();
char* app_get_cache_path(void)
{
  return app_get_resource_path();
}

// [DllImport(Libraries.AppCommon, EntryPoint = "app_get_shared_data_path")]
// internal static extern string AppGetSharedDataPath();
char* app_get_shared_data_path(void)
{
  return app_get_resource_path();
}

// [DllImport(Libraries.AppCommon, EntryPoint = "app_get_shared_resource_path")]
// internal static extern string AppGetSharedResourcePath();
char* app_get_shared_resource_path(void)
{
  return app_get_resource_path();
}

// [DllImport(Libraries.AppCommon, EntryPoint = "app_get_shared_trusted_path")]
// internal static extern string AppGetSharedTrustedPath();
char* app_get_shared_trusted_path(void)
{
  return app_get_resource_path();
}

// [DllImport(Libraries.AppCommon, EntryPoint = "app_get_tep_resource_path")]
// internal static extern string AppGetTepResourcePath();
char* app_get_tep_resource_path(void)
{
  return app_get_resource_path();
}

// [DllImport(Libraries.AppCommon, EntryPoint = "app_get_external_cache_path")]
// internal static extern string AppGetExternalCachePath();
char* app_get_external_cache_path(void)
{
  return app_get_resource_path();
}

// [DllImport(Libraries.AppCommon, EntryPoint = "app_get_external_data_path")]
// internal static extern string AppGetExternalDataPath();
char* app_get_external_data_path(void)
{
  return app_get_resource_path();
}

// [DllImport(Libraries.AppCommon, EntryPoint = "app_get_external_shared_data_path")]
// internal static extern string AppGetExternalSharedDataPath();
char* app_get_external_shared_data_path(void)
{
  return app_get_resource_path();
}

// [DllImport(Libraries.AppCommon, EntryPoint = "app_get_version")]
// internal static extern ErrorCode AppGetVersion(out string version);
int app_get_version(char** version)
{
  version = strdup("1.1.1");
  return APP_ERROR_NONE;
}

// [DllImport(Libraries.AppCommon, EntryPoint = "app_event_get_low_memory_status")]
// internal static extern ErrorCode AppEventGetLowMemoryStatus(IntPtr handle, out LowMemoryStatus status);
typedef enum {
  APP_EVENT_LOW_MEMORY_NORMAL = 0x01, /**< Normal status */
  APP_EVENT_LOW_MEMORY_SOFT_WARNING = 0x02, /**< Soft warning status */
  APP_EVENT_LOW_MEMORY_HARD_WARNING = 0x04, /**< Hard warning status */
} app_event_low_memory_status_e;
int app_event_get_low_memory_status(app_event_info_h event_info, app_event_low_memory_status_e *status)
{
  int ret;

  if (event_info == NULL || status == NULL)
    return APP_ERROR_INVALID_PARAMETER;

  if (event_info->type != APP_EVENT_LOW_MEMORY)
    return APP_ERROR_INVALID_PARAMETER;

  *status = APP_EVENT_LOW_MEMORY_NORMAL;
  return APP_ERROR_NONE;
}

// [DllImport(Libraries.AppCommon, EntryPoint = "app_event_get_low_battery_status")]
// internal static extern ErrorCode AppEventGetLowBatteryStatus(IntPtr handle, out LowBatteryStatus status);
typedef enum {
  APP_EVENT_LOW_BATTERY_POWER_OFF = 1, /**< The battery status is under 1% */
  APP_EVENT_LOW_BATTERY_CRITICAL_LOW, /**< The battery status is under 5% */
} app_event_low_battery_status_e;

static int __app_convert_low_battery(void *val)
{
  switch (*(int *)val) {
  case VCONFKEY_SYSMAN_BAT_POWER_OFF:
    return APP_EVENT_LOW_BATTERY_POWER_OFF;
  case VCONFKEY_SYSMAN_BAT_CRITICAL_LOW:
  default:
    return -1;
  }
}
int app_event_get_low_battery_status(app_event_info_h event_info, app_event_low_battery_status_e *status)
{
  int ret;

  if (event_info == NULL || status == NULL)
    return APP_ERROR_INVALID_PARAMETER;

  if (event_info->type != APP_EVENT_LOW_BATTERY)
    return APP_ERROR_INVALID_PARAMETER;

  *status = APP_EVENT_LOW_BATTERY_CRITICAL_LOW;;
  return APP_ERROR_NONE;
}

// [DllImport(Libraries.AppCommon, EntryPoint = "app_event_get_language")]
// internal static extern ErrorCode AppEventGetLanguage(IntPtr handle, out string lang);
int app_event_get_language(app_event_info_h event_info, char **lang)
{
  if (event_info == NULL || event_info->value == NULL || lang == NULL)
    return APP_ERROR_INVALID_PARAMETER;

  if (event_info->type != APP_EVENT_LANGUAGE_CHANGED)
    return APP_ERROR_INVALID_CONTEXT;

  *lang = strdup(event_info->value);

  return APP_ERROR_NONE;
}

// [DllImport(Libraries.AppCommon, EntryPoint = "app_event_get_region_format")]
// internal static extern ErrorCode AppEventGetRegionFormat(IntPtr handle, out string region);
int app_event_get_region_format(app_event_info_h event_info, char **region)
{
  if (event_info == NULL || event_info->value == NULL || region == NULL)
    return APP_ERROR_INVALID_PARAMETER;

  if (event_info->type != APP_EVENT_REGION_FORMAT_CHANGED)
    return APP_ERROR_INVALID_CONTEXT;

  *region = strdup(event_info->value);

  return APP_ERROR_NONE;
}

// [DllImport(Libraries.AppCommon, EntryPoint = "app_resource_manager_get")]
// internal static extern ErrorCode AppResourceManagerGet(ResourceCategory category, string id, out string path);
int app_resource_manager_get(app_resource_e type, const char *id, char **path)
{
  *path=strdup("/tmp/a");
  return APP_ERROR_NONE;
}

// [DllImport(Libraries.Application, EntryPoint = "app_resource_manager_get")]
// internal static extern ErrorCode LegacyAppResourceManagerGet(ResourceCategory category, string id, out string path);

// [DllImport(Libraries.AppCommon, EntryPoint = "app_event_get_device_orientation")]
// internal static extern ErrorCode AppEventGetDeviceOrientation(IntPtr handle, out DeviceOrientation orientation);
int app_event_get_device_orientation(app_event_info_h event_info, app_device_orientation_e *orientation)
{
  if (event_info == NULL || orientation == NULL)
    return APP_ERROR_INVALID_PARAMETER)

  if (event_info->type != APP_EVENT_DEVICE_ORIENTATION_CHANGED)
    return APP_ERROR_INVALID_CONTEXT;

  *orientation = 0;//PORTRAIT

  return APP_ERROR_NONE;
}

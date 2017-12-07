#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include "app_manager_internal.h"

extern "C"
{

struct app_context_s {
  char *app_id;
  pid_t pid;
  char *pkg_id;
  app_state_e app_state;
  bool is_sub_app;
  char *instance_id;
};

typedef struct _foreach_context_ {
  app_manager_app_context_cb callback;
  void *user_data;
  bool iteration;
} foreach_context_s;

typedef struct _retrieval_context_ {
  const char *app_id;
  pid_t pid;
  char *pkg_id;
  app_state_e app_state;
  bool is_sub_app;
  bool matched;
  const char *instance_id;
} retrieval_context_s;

typedef void *pkgmgrinfo_appinfo_h;
typedef void *pkgmgrinfo_pkginfo_filter_h;
typedef void *pkgmgrinfo_appinfo_metadata_filter_h;
typedef void *pkgmgrinfo_appinfo_filter_h;

struct app_info_s {
  char *app_id;
  pkgmgrinfo_appinfo_h pkg_app_info;
};

struct app_info_filter_s {
  pkgmgrinfo_appinfo_filter_h pkg_app_info_filter;
};

struct app_info_metadata_filter_s {
  pkgmgrinfo_appinfo_metadata_filter_h pkg_app_info_metadata_filter;
};

typedef struct _foreach_metada_context_ {
  app_info_metadata_cb callback;
  void *user_data;
} foreach_metadata_context_s;

typedef struct _foreach_category_ {
  app_info_category_cb callback;
  void *user_data;
} foreach_category_context_s;



// [DllImport(Libraries.AppManager, EntryPoint = "app_manager_set_app_context_event_cb")]
// internal static extern ErrorCode AppManagerSetAppContextEvent(AppManagerAppContextEventCallback callback, IntPtr userData);
int app_manager_set_app_context_event_cb( app_manager_app_context_event_cb callback, void * user_data)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_manager_unset_app_context_event_cb")]
// internal static extern void AppManagerUnSetAppContextEvent();
void app_manager_unset_app_context_event_cb (void)
{
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_manager_foreach_running_app_context")]
// internal static extern ErrorCode AppManagerForeachRunningAppContext(AppManagerAppContextCallback callback, IntPtr userData);
int app_manager_foreach_running_app_context(app_manager_app_context_cb callback, void *user_data)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_manager_foreach_app_context")]
// internal static extern ErrorCode AppManagerForeachAppContext(AppManagerAppContextCallback callback, IntPtr userData);
int app_manager_foreach_app_context(app_manager_app_context_cb callback, void *user_data)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_manager_get_app_context")]
// internal static extern ErrorCode AppManagerGetAppContext(string applicationId, out IntPtr handle);
int app_manager_get_app_context(const char* app_id, app_context_h *app_context)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_manager_get_app_id")]
// internal static extern ErrorCode AppManagerGetAppId(int processId, out string applicationId);
int app_manager_get_app_id (pid_t pid, char **appid)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_manager_is_running")]
// internal static extern ErrorCode AppManagerIsRunning(string applicationId, out bool running);
int app_manager_is_running (const char *appid, bool *running)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_manager_resume_app")]
// internal static extern ErrorCode AppManagerResumeApp(IntPtr handle)
int app_manager_resume_app (app_context_h handle)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_manager_request_terminate_bg_app")]
// internal static extern ErrorCode AppManagerRequestTerminateBgApp(IntPtr handle)
int app_manager_request_terminate_bg_app (app_context_h handle)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_manager_foreach_app_info")]
// internal static extern ErrorCode AppManagerForeachAppInfo(AppManagerAppInfoCallback callback, IntPtr userData)
int app_manager_foreach_app_info(app_manager_app_info_cb callback, void *user_data)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_manager_get_app_info")]
// internal static extern ErrorCode AppManagerGetAppInfo(string applicationId, out IntPtr handle)
int app_manager_get_app_info(const char * app_id, app_info_h * app_info)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_manager_get_shared_data_path")]
// internal static extern ErrorCode AppManagerGetSharedDataPath(string applicationId, out string path)
int app_manager_get_shared_data_path (const char *appid, char **path)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_manager_get_shared_resource_path")]
// internal static extern ErrorCode AppManagerGetSharedResourcePath(string applicationId, out string path)
int app_manager_get_shared_resource_path (const char *appid, char **path)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_manager_get_shared_trusted_path")]
// internal static extern ErrorCode AppManagerGetSharedTrustedPath(string applicationId, out string path)
int app_manager_get_shared_trusted_path (const char *appid, char **path)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_manager_get_external_shared_data_path")]
// internal static extern ErrorCode AppManagerGetExternalSharedDataPath(string applicationId, out string path)
int app_manager_get_external_shared_data_path (const char *appid, char **path)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_manager_event_create")]
// internal static extern ErrorCode AppManagerEventCreate(out IntPtr handle)
int app_manager_event_create (app_manager_event_h *handle)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_manager_event_set_status")]
// internal static extern ErrorCode AppManagerEventSetStatus(IntPtr handle, AppManagerEventStatusType statusType)
int app_manager_event_set_status (app_manager_event_h handle, int status_type)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_manager_set_event_cb")]
// internal static extern ErrorCode AppManagerSetEventCallback(IntPtr handle, AppManagerEventCallback callback, IntPtr userData)
int app_manager_set_event_cb (app_manager_event_h handle, app_manager_event_cb callback, void *user_data)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_manager_unset_event_cb")]
// internal static extern ErrorCode AppManagerUnSetEventCallback(IntPtr handle)
int app_manager_unset_event_cb (app_manager_event_h handle)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_manager_event_destroy")]
// internal static extern ErrorCode AppManagerEventDestroy(IntPtr handle)
int app_manager_event_destroy (app_manager_event_h handle)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_manager_terminate_app")]
// internal static extern ErrorCode AppManagerTerminateApp(IntPtr handle)
int app_manager_terminate_app (app_context_h app_context)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_manager_get_app_context_by_instance_id")]
// internal static extern ErrorCode AppManagerGetAppContextByInstanceId(string applicationId, string instanceId, out IntPtr handle)
int app_manager_get_app_context_by_instance_id (const char *app_id, const char *instance_id, app_context_h *app_context)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_context_destroy")]
// internal static extern ErrorCode AppContextDestroy(IntPtr handle)
int app_context_destroy(app_context_h app_context)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_context_get_app_id")]
// internal static extern ErrorCode AppContextGetAppId(IntPtr handle, out string applicationId)
int app_context_get_app_id(app_context_h app_context, char **app_id)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_context_get_package_id")]
// internal static extern ErrorCode AppContextGetPackageId(IntPtr handle, out string packageId)
int app_context_get_package_id(app_context_h app_context, char **package_id)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_context_get_pid")]
// internal static extern ErrorCode AppContextGetPid(IntPtr handle, out int processId)
int app_context_get_pid (app_context_h app_context, pid_t *pid)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_context_get_app_state")]
// internal static extern ErrorCode AppContextGetAppState(IntPtr handle, out int state)
int app_context_get_app_state (app_context_h app_context, app_state_e *state)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_context_is_terminated")]
// internal static extern ErrorCode AppContextIsTerminated(IntPtr handle, out bool terminated)
int app_context_is_terminated (app_context_h app_context, bool *terminated)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_context_is_equal")]
// internal static extern ErrorCode AppContextIsEqual(IntPtr first, IntPtr second, out bool equal)
int app_context_is_equal (app_context_h lhs, app_context_h rhs, bool *equal)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_context_is_sub_app")]
// internal static extern ErrorCode AppContextIsSubApp(IntPtr handle, out bool is_sub_app)
int app_context_is_sub_app (app_context_h app_context, bool *is_sub_app)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_context_clone")]
// internal static extern ErrorCode AppContextClone(out IntPtr destination, IntPtr source)
int app_context_clone (app_context_h *clone, app_context_h app_context)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_info_create")]
// internal static extern ErrorCode AppInfoCreate(string applicationId, out IntPtr handle)
int app_info_create (const char *app_id, app_info_h *app_info)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_info_destroy")]
// internal static extern ErrorCode AppInfoDestroy(IntPtr handle)
int app_info_destroy (app_info_h app_info)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_info_get_app_id")]
// internal static extern ErrorCode AppInfoGetAppId(IntPtr handle, out string applicationId)
int app_info_get_app_id (app_info_h app_info, char **app_id)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_info_get_exec")]
// internal static extern ErrorCode AppInfoGetExec(IntPtr handle, out string exec)
int app_info_get_exec (app_info_h app_info, char **exec)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_info_get_label")]
// internal static extern ErrorCode AppInfoGetLabel(IntPtr handle, out string label)
int app_info_get_label (app_info_h app_info, char **label)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_info_get_localed_label")]
// internal static extern ErrorCode AppInfoGetLocaledLabel(string applicationId, string locale, out string label)
int app_info_get_localed_label (const char *app_id, const char *locale, char **label)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_info_get_icon")]
// internal static extern ErrorCode AppInfoGetIcon(IntPtr handle, out string path)
int app_info_get_icon (app_info_h app_info, char **path)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_info_get_package")]
// internal static extern ErrorCode AppInfoGetPackage(IntPtr handle, out string package)
int app_info_get_package (app_info_h app_info, char **package)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_info_get_type")]
// internal static extern ErrorCode AppInfoGetType(IntPtr handle, out string type)
int app_info_get_type (app_info_h app_info, char **type)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_info_foreach_metadata")]
// internal static extern ErrorCode AppInfoForeachMetadata(IntPtr handle, AppInfoMetadataCallback callback, IntPtr userData)
int app_info_foreach_metadata(app_info_h app_info, app_info_metadata_cb callback, void *user_data)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_info_is_nodisplay")]
// internal static extern ErrorCode AppInfoIsNodisplay(IntPtr handle, out bool noDisplay)
int app_info_is_nodisplay (app_info_h app_info, bool *nodisplay)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_info_is_equal")]
// internal static extern ErrorCode AppInfoIsEqual(IntPtr first, IntPtr second, out bool equal)
int app_info_is_equal (app_info_h lhs, app_info_h rhs, bool *equal)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_info_is_enabled")]
// internal static extern ErrorCode AppInfoIsEnabled(IntPtr handle, out bool enabled)
int app_info_is_enabled (app_info_h app_info, bool *enabled)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_info_is_onboot")]
// internal static extern ErrorCode AppInfoIsOnBoot(IntPtr handle, out bool onBoot)
int app_info_is_onboot (app_info_h app_info, bool *onboot)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_info_is_preload")]
// internal static extern ErrorCode AppInfoIsPreLoad(IntPtr handle, out bool preLoaded)
int app_info_is_preload (app_info_h app_info, bool *preload)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_info_clone")]
// internal static extern ErrorCode AppInfoClone(out IntPtr destination, IntPtr source)
int app_info_clone(app_info_h * clone, app_info_h app_info)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_info_filter_create")]
// internal static extern ErrorCode AppInfoFilterCreate(out IntPtr handle)
int app_info_filter_create(app_info_filter_h * handle)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_info_filter_destroy")]
// internal static extern ErrorCode AppInfoFilterDestroy(IntPtr handle)
int app_info_filter_destroy(app_info_filter_h handle)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_info_filter_add_bool")]
// internal static extern ErrorCode AppInfoFilterAddBool(IntPtr handle, string property, bool value)
int app_info_filter_add_bool(app_info_filter_h handle, const char *property, const bool value)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_info_filter_add_string")]
// internal static extern ErrorCode AppInfoFilterAddString(IntPtr handle, string property, string value)
int app_info_filter_add_string(app_info_filter_h handle, const char *property, const char *value)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_info_filter_count_appinfo")]
// internal static extern ErrorCode AppInfoFilterCountAppinfo(IntPtr handle, out int count)
int app_info_filter_count_appinfo(app_info_filter_h handle, int *count)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_info_filter_foreach_appinfo")]
// internal static extern ErrorCode AppInfoFilterForeachAppinfo(IntPtr handle, AppInfoFilterCallback callback, IntPtr userData)
int app_info_filter_foreach_appinfo(app_info_filter_h handle, app_info_filter_cb callback, void * user_data)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_info_metadata_filter_create")]
// internal static extern ErrorCode AppInfoMetadataFilterCreate(out IntPtr handle)
int app_info_metadata_filter_create (app_info_metadata_filter_h *handle)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_info_metadata_filter_destroy")]
// internal static extern ErrorCode AppInfoMetadataFilterDestroy(IntPtr handle)
int app_info_metadata_filter_destroy (app_info_metadata_filter_h handle)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_info_metadata_filter_add")]
// internal static extern ErrorCode AppInfoMetadataFilterAdd(IntPtr handle, string key, string value)
int app_info_metadata_filter_add (app_info_metadata_filter_h handle, const char *key, const char *value)
{
  return 0;
}

// [DllImport(Libraries.AppManager, EntryPoint = "app_info_metadata_filter_foreach")]
// internal static extern ErrorCode AppInfoMetadataFilterForeach(IntPtr handle, AppInfoFilterCallback callback, IntPtr userData)
int app_info_metadata_filter_foreach (app_info_metadata_filter_h handle, app_info_filter_cb callback, void *user_data)
{
  return 0;
}

}

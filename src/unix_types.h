#pragma once

#include "config.h"

#ifndef HAVE_UID_T
typedef int uid_t;
#endif

#ifndef HAVE_GID_T
typedef int gid_t;
#endif

#ifndef HAVE_PID_T
typedef int pid_t;
#endif

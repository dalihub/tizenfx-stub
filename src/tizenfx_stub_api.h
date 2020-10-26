#pragma once

#ifdef BUILDING_TIZENFX_STUB
#ifdef _MSC_VER
#define TIZENFX_STUB_API __declspec(dllexport)
#else
#define TIZENFX_STUB_API
#endif
#else
#ifdef _MSC_VER
#define TIZENFX_STUB_API __declspec(dllimport)
#else
#define TIZENFX_STUB_API
#endif
#endif

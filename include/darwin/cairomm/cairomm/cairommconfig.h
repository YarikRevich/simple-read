#ifndef _CAIROMM_CONFIG_H
#define _CAIROMM_CONFIG_H

/* This file is part of cairomm. */

/* Define to omit deprecated API from the library. */
/* #undef CAIROMM_DISABLE_DEPRECATED */

/* Defined when the -Dbuild-exceptions-api=true configure argument was given */
#define CAIROMM_EXCEPTIONS_ENABLED 1

/* Major version number of cairomm. */
#define CAIROMM_MAJOR_VERSION 1

/* Minor version number of cairomm. */
#define CAIROMM_MINOR_VERSION 14

/* Micro version number of cairomm. */
#define CAIROMM_MICRO_VERSION 4

/* Enable DLL-specific stuff only when not building a static library */
#if !defined(__CYGWIN__) && \
    (defined(__MINGW32__) || defined (_MSC_VER)) && \
    !defined(CAIROMM_STATIC_LIB)
# define CAIROMM_DLL 1
#endif

#ifdef CAIROMM_DLL
# if defined(CAIROMM_BUILD)
#  define CAIROMM_API __declspec(dllexport)
# elif !defined (__GNUC__)
#  define CAIROMM_API __declspec(dllimport)
# else /* don't dllimport classes/methods on GCC/MinGW */
#  define CAIROMM_API
# endif
/* Build a static or non-native-Windows library */
#else
# define CAIROMM_API
#endif /* CAIROMM_DLL */

#endif /* _CAIROMM_CONFIG_H */

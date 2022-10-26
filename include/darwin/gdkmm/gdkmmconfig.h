#ifndef _GDKMM_CONFIG_H
#define _GDKMM_CONFIG_H

#include <pangommconfig.h>

/* Defined when the -Dbuild-x11-api=true configure argument was given */
/* #undef GDKMM_X11_BACKEND_ENABLED */

/* Define to omit deprecated API from gdkmm. */
/* #undef GDKMM_DISABLE_DEPRECATED */

/* Major version number of gdkmm. */
#define GDKMM_MAJOR_VERSION 3

/* Minor version number of gdkmm. */
#define GDKMM_MINOR_VERSION 24

/* Micro version number of gdkmm. */
#define GDKMM_MICRO_VERSION 7

/* Enable DLL-specific stuff only when not building a static library nor using gendef. */
#if !defined(__CYGWIN__) && defined(_WIN32) && \
    !defined(GDKMM_STATIC_LIB) && !defined(GDKMM_USE_GENDEF)
# define GDKMM_DLL 1
#endif

#ifdef GDKMM_DLL
# ifdef GDKMM_BUILD
#  define GDKMM_API __declspec(dllexport)
# elif !defined (__GNUC__)
#  define GDKMM_API __declspec(dllimport)
# else /* don't dllimport classes/methods on GCC/MinGW */
#  define GDKMM_API
# endif /* GDKMM_BUILD */
#else
/* Build a static library or a non-native-Windows library */
# define GDKMM_API
#endif /* GDKMM_DLL */

#endif /* !_GDKMM_CONFIG_H */

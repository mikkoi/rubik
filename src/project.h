#ifndef PROJECT_RUBIK_H
#define PROJECT_RUBIK_H

#if defined(__GNUC__) && defined(__GNUC_MINOR__)
#define GCC_VERSION_AT_LEAST(major, minor) \
((__GNUC__ > (major)) || \
 (__GNUC__ == (major) && __GNUC_MINOR__ >= (minor)))
#else
#define GCC_VERSION_AT_LEAST(major, minor) 0
#endif

#if GCC_VERSION_AT_LEAST(2,95)
#define RUBIK_ATTRIBUTE_UNUSED __attribute__ ((unused))
#else
#define RUBIK_ATTRIBUTE_UNUSED
#endif /* GCC 2.95 */

#if GCC_VERSION_AT_LEAST(7,0)
#define RUBIK_ATTRIBUTE_FALLTHROUGH __attribute__ ((fallthrough))
#else
#define RUBIK_ATTRIBUTE_FALLTHROUGH
#endif /* GCC 7.0 */

#define _FORTIFY_SOURCE 2

#endif


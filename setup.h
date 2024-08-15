#pragma once

/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at https://curl.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 * SPDX-License-Identifier: curl
 *
 ***************************************************************************/

#define CURL_STRICTER

/* Compile-time deprecation macros. */
#if defined(__GNUC__) &&                                                \
  ((__GNUC__ > 12) || ((__GNUC__ == 12) && (__GNUC_MINOR__ >= 1 ))) &&  \
  !defined(__INTEL_COMPILER) &&                                         \
  !defined(CURL_DISABLE_DEPRECATION) && !defined(BUILDING_LIBCURL)
#define CURL_DEPRECATED(version, message)                       \
  __attribute__((deprecated("since " # version ". " message)))
#define CURL_IGNORE_DEPRECATION(statements) \
      _Pragma("GCC diagnostic push") \
      _Pragma("GCC diagnostic ignored \"-Wdeprecated-declarations\"") \
      statements \
      _Pragma("GCC diagnostic pop")
#else
#define CURL_DEPRECATED(version, message)
#define CURL_IGNORE_DEPRECATION(statements)     statements
#endif

#include "system.h"          /* determine things run-time */

#include <stdio.h>
#include <limits.h>

#if defined(__FreeBSD__) || defined(__MidnightBSD__)
/* Needed for __FreeBSD_version or __MidnightBSD_version symbol definition */
#include <sys/param.h>
#endif

/* The include stuff here below is mainly for time_t! */
#include <sys/types.h>
#include <time.h>

#if defined(_WIN32) && !defined(_WIN32_WCE) && !defined(__CYGWIN__)
#if !(defined(_WINSOCKAPI_) || defined(_WINSOCK_H) || \
      defined(__LWIP_OPT_H__) || defined(LWIP_HDR_OPT_H))
/* The check above prevents the winsock2 inclusion if winsock.h already was
   included, since they can't co-exist without problems */
#include <winsock2.h>
#include <ws2tcpip.h>
#endif
#endif

/* HP-UX systems version 9, 10 and 11 lack sys/select.h and so does oldish
   libc5-based Linux systems. Only include it on systems that are known to
   require it! */
#if defined(_AIX) || defined(__NOVELL_LIBC__) || defined(__NetBSD__) || \
    defined(__minix) || defined(__INTEGRITY) || \
    defined(ANDROID) || defined(__ANDROID__) || defined(__OpenBSD__) || \
    defined(__CYGWIN__) || defined(AMIGA) || defined(__NuttX__) || \
   (defined(__FreeBSD_version) && (__FreeBSD_version < 800000)) || \
   (defined(__MidnightBSD_version) && (__MidnightBSD_version < 100000)) || \
    defined(__sun__) || defined(__serenity__) || defined(__vxworks__)
#include <sys/select.h>
#endif

#if !defined(_WIN32) && !defined(_WIN32_WCE)
#include <sys/socket.h>
#endif

#if !defined(_WIN32)
#include <sys/time.h>
#endif

/* Compatibility for non-Clang compilers */
#ifndef __has_declspec_attribute
#  define __has_declspec_attribute(x) 0
#endif

typedef struct Curl_easy CURL;
typedef struct Curl_share CURLSH;

/*
 * libcurl external API function linkage decorations.
 */
#define CURL_EXTERN
#if defined(_WIN32) && !defined(__LWIP_OPT_H__) && !defined(LWIP_HDR_OPT_H)
    typedef SOCKET curl_socket_t;
    #define CURL_SOCKET_BAD INVALID_SOCKET
#else
    typedef int curl_socket_t;
    #define CURL_SOCKET_BAD -1
#endif
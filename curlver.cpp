module curl;

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

const char* LIBCURL_COPYRIGHT = "Daniel Stenberg, <daniel@haxx.se>.";
const char* LIBCURL_VERSION = "8.8.0";
int LIBCURL_VERSION_MAJOR = 8;
int LIBCURL_VERSION_MINOR = 8;
int LIBCURL_VERSION_PATCH = 0;
int LIBCURL_VERSION_NUM = 0x080800;
const char* LIBCURL_TIMESTAMP = "2024-05-22";

int CURL_VERSION_BITS(int x, int y, int z) {
    return (x << 16) | (y << 8) | z;
}

bool CURL_AT_LEAST_VERSION(int x, int y, int z) {
    return LIBCURL_VERSION_NUM >= CURL_VERSION_BITS(x, y, z);
}
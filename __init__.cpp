module;
export module curl;

/* unfortunately, the easy.h and multi.h include files need options and info
  stuff before they can be included! */


export namespace curl {
    const char* LIBCURL_COPYRIGHT;
    const char* LIBCURL_VERSION;
    int LIBCURL_VERSION_MAJOR;
    int LIBCURL_VERSION_MINOR;
    int LIBCURL_VERSION_PATCH;
    int LIBCURL_VERSION_NUM;
    const char* LIBCURL_TIMESTAMP;

    int CURL_VERSION_BITS(int x, int y, int z);
    bool CURL_AT_LEAST_VERSION(int x, int y, int z);


    // Constants
    constexpr unsigned int CURL_BLOB_COPY = 1;
    constexpr unsigned int CURL_BLOB_NOCOPY = 0;

    // // Structures
    // struct curl_blob {
    //     void *data;
    //     std::size_t len;
    //     unsigned int flags; // bit 0 is defined, the rest are reserved and should be left zeroes
    // };

    // // Function declarations
    // CURL* curl_easy_init(void);
    // CURLcode curl_easy_setopt(CURL *curl, CURLoption option, ...);
    // CURLcode curl_easy_perform(CURL *curl);
    // void curl_easy_cleanup(CURL *curl);

    // CURLcode curl_easy_getinfo(CURL *curl, CURLINFO info, ...);
    // CURL* curl_easy_duphandle(CURL *curl);
    // void curl_easy_reset(CURL *curl);
    // CURLcode curl_easy_recv(CURL *curl, void *buffer, std::size_t buflen, std::size_t *n);
    // CURLcode curl_easy_send(CURL *curl, const void *buffer, std::size_t buflen, std::size_t *n);
    // CURLcode curl_easy_upkeep(CURL *curl);
}
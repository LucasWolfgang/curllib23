module curl;

/* enum for the different supported SSL backends */
typedef enum {
  CURLSSLBACKEND_NONE = 0,
  CURLSSLBACKEND_OPENSSL = 1,
  CURLSSLBACKEND_GNUTLS = 2,
  CURLSSLBACKEND_NSS                    CURL_DEPRECATED(8.3.0, "") = 3,
  CURLSSLBACKEND_OBSOLETE4 = 4,  /* Was QSOSSL. */
  CURLSSLBACKEND_GSKIT                  CURL_DEPRECATED(8.3.0, "") = 5,
  CURLSSLBACKEND_POLARSSL               CURL_DEPRECATED(7.69.0, "") = 6,
  CURLSSLBACKEND_WOLFSSL = 7,
  CURLSSLBACKEND_SCHANNEL = 8,
  CURLSSLBACKEND_SECURETRANSPORT = 9,
  CURLSSLBACKEND_AXTLS                  CURL_DEPRECATED(7.61.0, "") = 10,
  CURLSSLBACKEND_MBEDTLS = 11,
  CURLSSLBACKEND_MESALINK               CURL_DEPRECATED(7.82.0, "") = 12,
  CURLSSLBACKEND_BEARSSL = 13,
  CURLSSLBACKEND_RUSTLS = 14
} curl_sslbackend;

struct curl_httppost_flag {
    /* specified content is a file name */
    unsigned int CURL_HTTPPOST_FILENAME : 1;
    /* specified content is a file name */  
    unsigned int CURL_HTTPPOST_READFILE : 1; 
    /* name is only stored pointer do not free in formfree */ 
    unsigned int CURL_HTTPPOST_PTRNAME : 1;  
    /* contents is only stored pointer do not free in formfree */
    unsigned int CURL_HTTPPOST_PTRCONTENTS : 1;
    /* upload file from buffer */
    unsigned int CURL_HTTPPOST_BUFFER : 1;
    /* upload file from pointer contents */
    unsigned int CURL_HTTPPOST_PTRBUFFER : 1;
    /* upload file contents by using the regular read callback to get the data and
   pass the given pointer as custom pointer */
    unsigned int CURL_HTTPPOST_CALLBACK : 1;
    /* use size in 'contentlen', added in 7.46.0 */
    unsigned int CURL_HTTPPOST_LARGE : 1;
    unsigned int reserved : 24; // 29 bits reserved for future use

    // Convert struct to int
    unsigned int toInt() const {
        return flagA | (flagB << 1) | (flagC << 2);
    }

    // Convert int to struct
    static FlagStruct fromInt(unsigned int value) {
        FlagStruct flags;
        flags.flagA = value & 0x1;
        flags.flagB = (value >> 1) & 0x1;
        flags.flagC = (value >> 2) & 0x1;
        // reserved bits are zero by default
        return flags;
    }
};

struct curl_httppost {
  struct curl_httppost *next;       /* next entry in the list */
  char *name;                       /* pointer to allocated name */
  long namelength;                  /* length of name length */
  char *contents;                   /* pointer to allocated data contents */
  long contentslength;              /* length of contents field, see also
                                       CURL_HTTPPOST_LARGE */
  char *buffer;                     /* pointer to allocated buffer contents */
  long bufferlength;                /* length of buffer field */
  char *contenttype;                /* Content-Type */
  struct curl_slist *contentheader; /* list of extra headers for this form */
  struct curl_httppost *more;       /* if one field name has more than one
                                       file, this link should link to following
                                       files */
  long flags;                       /* as defined below */

  char *showfilename;               /* The file name to show. If not set, the
                                       actual file name will be used (if this
                                       is a file part) */
  void *userp;                      /* custom pointer used for
                                       HTTPPOST_CALLBACK posts */
  curl_off_t contentlen;            /* alternative length of contents
                                       field. Used if CURL_HTTPPOST_LARGE is
                                       set. Added in 7.46.0 */
};
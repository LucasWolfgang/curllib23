add_library(curl)

target_sources(curl
  PRIVATE
    "curlver.cpp"
    "structs.cpp"
  PUBLIC
    FILE_SET "curl_module"
    TYPE "CXX_MODULES"
    FILES
      "__init__.cpp"
)

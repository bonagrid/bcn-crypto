cmake_minimum_required(VERSION 3.14)
project(bcn-crypto C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(BCN_CONFIG_txt "${CMAKE_CURRENT_SOURCE_DIR}/configs/bcn-config.h")
add_compile_definitions(MBEDTLS_CONFIG_FILE="${BCN_CONFIG_txt}")

set(ENABLE_TESTING OFF CACHE INTERNAL "")
set(ENABLE_PROGRAMS OFF CACHE INTERNAL "")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/bcn-tls ${CMAKE_CURRENT_BINARY_DIR}/bcn-tls-build)

add_library(bcn_crypto SHARED
    library/sha256.hpp
    library/sha256.cpp
)

target_include_directories(bcn_crypto PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/configs
    ${CMAKE_CURRENT_SOURCE_DIR}/bcn-tls/include
    ${CMAKE_CURRENT_SOURCE_DIR}/bcn-tls/library
)

target_link_libraries(bcn_crypto PRIVATE mbedtls mbedx509 tfpsacrypto)

find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(DOXYGEN_PROJECT_NAME "BCN-Crypto Module")
    set(DOXYGEN_PROJECT_BRIEF "crypto")
    set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/docs")
    set(DOXYGEN_RECURSIVE YES)
    set(DOXYGEN_OPTIMIZE_OUTPUT_FOR_C YES)
    set(DOXYGEN_GENERATE_LATEX NO)
    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_EXTRACT_ALL YES)
    
    doxygen_add_docs(doc
        "${CMAKE_CURRENT_SOURCE_DIR}/library"
        COMMENT "Generating API documentation with Doxygen"
    )
endif()
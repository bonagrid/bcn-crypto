/**
 * \file bcn-config.h
 *
 * \brief Optimized Configuration for High-Performance Mesh/Tunnelling Crypto Stack (Mbed TLS 4.0)
 */

#ifndef MBEDTLS_CONFIG_H
#define MBEDTLS_CONFIG_H

#define MBEDTLS_CONFIG_VERSION 0x04000000

/* ========================================================================== */
/* SECTION: PSA Crypto Configuration (Modern Algorithms Only)                 */
/* ========================================================================== */

/* Hash & Key Derivation */
#ifndef PSA_WANT_ALG_SHA_256
#define PSA_WANT_ALG_SHA_256
#endif
#ifndef PSA_WANT_ALG_SHA_384
#define PSA_WANT_ALG_SHA_384
#endif
#ifndef PSA_WANT_ALG_HKDF
#define PSA_WANT_ALG_HKDF
#endif
#ifndef PSA_WANT_ALG_HMAC
#define PSA_WANT_ALG_HMAC
#endif

/* ECC Curves & Algorithms */
#ifndef PSA_WANT_ALG_ECDH
#define PSA_WANT_ALG_ECDH
#endif
#ifndef PSA_WANT_ALG_ECDSA
#define PSA_WANT_ALG_ECDSA
#endif
#ifndef PSA_WANT_ECC_SECP_R1_256
#define PSA_WANT_ECC_SECP_R1_256
#endif
#ifndef PSA_WANT_ECC_SECP_R1_384
#define PSA_WANT_ECC_SECP_R1_384
#endif

/* AEAD Ciphers */
#ifndef PSA_WANT_ALG_CHACHA20_POLY1305
#define PSA_WANT_ALG_CHACHA20_POLY1305
#endif
#ifndef PSA_WANT_ALG_GCM
#define PSA_WANT_ALG_GCM
#endif

/* ========================================================================== */
/* SECTION: Platform & System Layer                                           */
/* ========================================================================== */

#define MBEDTLS_NET_C
#define MBEDTLS_TIMING_C
#define MBEDTLS_HAVE_TIME

/* ========================================================================== */
/* SECTION: Core Infrastructure Modules                                       */
/* ========================================================================== */

#define MBEDTLS_PSA_CRYPTO_C
#define MBEDTLS_PSA_CRYPTO_CLIENT
#define MBEDTLS_PK_C
#define MBEDTLS_PK_PARSE_C
#define MBEDTLS_PK_WRITE_C
#define MBEDTLS_ASN1_PARSE_C
#define MBEDTLS_ASN1_WRITE_C

/* MBEDTLS_OID_C удален в 4.0, внутренности управляются автоматически */

/* System utilities */
#define MBEDTLS_ERROR_C
#define MBEDTLS_ERROR_STRERROR_DUMMY
#define MBEDTLS_VERSION_C

/* ========================================================================== */
/* SECTION: TLS/DTLS Protocol Core                                            */
/* ========================================================================== */

#define MBEDTLS_DEBUG_C
#define MBEDTLS_SSL_TLS_C
#define MBEDTLS_SSL_CLI_C
#define MBEDTLS_SSL_SRV_C

/* Protocols (TLS 1.3 & DTLS for UDP) */
#define MBEDTLS_SSL_PROTO_TLS1_2
#define MBEDTLS_SSL_PROTO_TLS1_3
#define MBEDTLS_SSL_PROTO_DTLS

/* ========================================================================== */
/* SECTION: Performance & Tunnelling Optimizations                            */
/* ========================================================================== */

#define MBEDTLS_SSL_VARIABLE_BUFFER_LENGTH
#define MBEDTLS_SSL_MAX_FRAGMENT_LENGTH

/* DTLS Tunnelling & Anti-DoS Features */
#define MBEDTLS_SSL_DTLS_ANTI_REPLAY
#define MBEDTLS_SSL_DTLS_CLIENT_PORT_REUSE
#define MBEDTLS_SSL_DTLS_CONNECTION_ID
#define MBEDTLS_SSL_DTLS_HELLO_VERIFY
#define MBEDTLS_SSL_COOKIE_C

/* Session management */
#define MBEDTLS_SSL_ALPN
#define MBEDTLS_SSL_CACHE_C
#define MBEDTLS_SSL_CONTEXT_SERIALIZATION
#define MBEDTLS_SSL_EXTENDED_MASTER_SECRET
#define MBEDTLS_SSL_KEEP_PEER_CERTIFICATE
#define MBEDTLS_SSL_KEYING_MATERIAL_EXPORT
#define MBEDTLS_SSL_SERVER_NAME_INDICATION
#define MBEDTLS_SSL_SESSION_TICKETS
#define MBEDTLS_SSL_TLS1_3_COMPATIBILITY_MODE

/* ========================================================================== */
/* SECTION: Key Exchange Modes (ECC / PSK focused)                            */
/* ========================================================================== */

#define MBEDTLS_KEY_EXCHANGE_ECDHE_ECDSA_ENABLED
#define MBEDTLS_KEY_EXCHANGE_ECDHE_PSK_ENABLED
#define MBEDTLS_KEY_EXCHANGE_PSK_ENABLED

#define MBEDTLS_SSL_TLS1_3_KEY_EXCHANGE_MODE_EPHEMERAL_ENABLED
#define MBEDTLS_SSL_TLS1_3_KEY_EXCHANGE_MODE_PSK_ENABLED
#define MBEDTLS_SSL_TLS1_3_KEY_EXCHANGE_MODE_PSK_EPHEMERAL_ENABLED

/* ========================================================================== */
/* SECTION: X.509 Certificate Support                                         */
/* ========================================================================== */

#define MBEDTLS_X509_USE_C
#define MBEDTLS_X509_CRT_PARSE_C
#define MBEDTLS_X509_CRL_PARSE_C
#define MBEDTLS_X509_CSR_PARSE_C
#define MBEDTLS_X509_CREATE_C
#define MBEDTLS_X509_CRT_WRITE_C
#define MBEDTLS_X509_CSR_WRITE_C

#endif /* MBEDTLS_CONFIG_H */
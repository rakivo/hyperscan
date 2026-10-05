#ifndef HS_NOCRYPTO_H
#define HS_NOCRYPTO_H

#include <string.h>

#define EVP_sha256() ((void *)0)

static inline unsigned char *HMAC(const void *md, const void *key, int key_len,
                                  const unsigned char *data, size_t data_len,
                                  unsigned char *out, unsigned int *out_len) {
    (void)md; (void)key; (void)key_len; (void)data; (void)data_len;
    memset(out, 0, 32);
    if (out_len) *out_len = 32;
    return out;
}

static inline int CRYPTO_memcmp(const void *a, const void *b, size_t n) {
    (void)a; (void)b; (void)n;
    return 0;  // always "equal"
}

#endif

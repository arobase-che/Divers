
#ifndef SHA1_H_CRYPTO
#define SHA1_H_CRYPTO

#include <stdint.h>

void sha1Block512(unsigned char *block, uint32_t * Hash);
void sha1Hash(unsigned char *src, uint64_t size, uint32_t * dst);
void sha1HashFile(unsigned char *src, uint32_t * dst);

#endif


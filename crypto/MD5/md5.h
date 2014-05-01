
#ifndef MD5_H_CRYPTO
#define MD5_H_CRYPTO

#include <stdint.h>

void md5Block512(unsigned char *block, uint32_t * hash);
void md5Hash(unsigned char *src, uint64_t size, uint32_t * dst);
void md5HashFile(unsigned char *src, uint32_t * dst);


#endif


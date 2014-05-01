#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MD5_HMAC
#define KEY "key"
#define SRC "The quick brown fox jumps over the lazy dog"

#ifdef MD5_HMAC
  #include "../md5.c"
  #define BLOCK_SIZE 64
  #define BLOCK_SIZE_OUT 16
  #define FUNCTION md5Hash
#else
  #ifdef SHA1_HMAC
    #include "../sha1.c"
    #define BLOCK_SIZE 64
    #define BLOCK_SIZE_OUT 20
    #define FUNCTION sha1Hash
  #endif
#endif

void hmacHash(void (*H)(unsigned char *, uint64_t, uint32_t *), const char* key, uint32_t* dst, size_t sizeBloc)
{
  uint32_t* opad, *ipad, *bloc;
  opad = malloc( sizeof *opad * sizeBloc);
  ipad = malloc( sizeof *opad * sizeBloc);
  memset(opad, 0x5C, 4 * sizeBloc);
  memset(ipad, 0x36, 4 * sizeBloc);
  
}
int main(void)
{
  unsigned char opad[BLOCK_SIZE], ipad[BLOCK_SIZE], bloc[BLOCK_SIZE], key[BLOCK_SIZE] = {0};
  unsigned char cat[BLOCK_SIZE + BLOCK_SIZE_OUT], cat1[BLOCK_SIZE + strlen(SRC)];
  
  union u {
    uint32_t d[BLOCK_SIZE_OUT*8/32];
  } out1 = {0}, out2 = {0};
  memset(opad, 0x5C, BLOCK_SIZE);
  memset(ipad, 0x36, BLOCK_SIZE);
  
  strcpy(key, KEY);
  // K ^ OPAD &&  K ^ IPAD
  for(int i = 0 ; i < BLOCK_SIZE ; i++) {
    opad[i] ^= key[i];
    ipad[i] ^= key[i];
  }
  //FUNCTION(opad, BLOCK_SIZE, out2.d);
  
  // K ^ IPAD || SRC
  for(int i = 0 ; i < BLOCK_SIZE ; i++)
    cat1[i] = ipad[i];
  for(int i = 0 ; i < strlen(SRC) ; i++)
    cat1[i+BLOCK_SIZE] = SRC[i];
  // H ( K ^ IPAD || SRC )
  FUNCTION(cat1, BLOCK_SIZE+strlen(SRC), out1.d);
  
  for( int i = 0 ; i < BLOCK_SIZE ; i++)
    cat[i] = opad[i];
  for( int i = 0 ; i < BLOCK_SIZE_OUT*8/32 ; i++)
    cat[BLOCK_SIZE+i*4] =   (0xFF000000 & out1.d[i]) >> 24,
    cat[BLOCK_SIZE+i*4+1] = (0x00FF0000 & out1.d[i]) >> 16,
    cat[BLOCK_SIZE+i*4+2] = (0x0000FF00 & out1.d[i]) >>  8,
    cat[BLOCK_SIZE+i*4+3] = (0x000000FF & out1.d[i]) >>  0;
  FUNCTION(cat, BLOCK_SIZE + BLOCK_SIZE_OUT, out2.d);
  for(int i = 0 ; i < BLOCK_SIZE_OUT*8/32 ; i++)
    printf("%.8x", out2.d[i]);
  puts("");
  
}


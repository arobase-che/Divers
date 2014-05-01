/*♡ Copying is an act of love. Please copy.
    
    
  Codé par @che - Implémentation de fonction de hashage MD5 / Fichier et Chaine
  Licence - WTFPL
*/

#include <stdint.h>
#include "md5.h"


/** Fonction d'exemple **/

#include <stdio.h>

int main(void)
{
  uint32_t dst[4];
  md5Hash("abc", 3 , dst);
  printf("%+.2X %.2X %.2X %.2X\n", dst[0], dst[1], dst[2], dst[3]);
  md5Hash("ache", 4 , dst);
  printf("%+.2X %.2X %.2X %.2X\n", dst[0], dst[1], dst[2], dst[3]);
  md5HashFile("main.c", dst);
  printf("%+.2X %.2X %.2X %.2X\n", dst[0], dst[1], dst[2], dst[3]);
}




#define ROT_L(x, n)   ( (((x) << n) & 0xFFFFFFFF ) | ((x) >> (32 - n)) )

void md5Block512(unsigned char *block, uint32_t * H)
{
  uint32_t r[64] = { 7, 12, 17, 22, 5, 9, 14, 20, 4, 11, 16, 23, 6, 10, 15, 21 }, k[64] = {
        0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,	// Round 1 
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501, 
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be, 
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821, 
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,	// Round 2 
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8, 
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed, 
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a, 
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,	// Round 3 
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70, 
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05, 
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665, 
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,	// Round 4
        0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1, 
        0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1, 
        0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391}, i;
#define ROTATE_VALUE(X)       h[0] += F + w[tmp] + k[i+X*4]; \
                           h[0] =  ROT_L(h[0], r[i%4+X]) + h[1]; \
                           tmp = h[0]; \
                           h[0] = h[3]; \
                           h[3] = h[2]; \
                           h[2] = h[1]; \
                           h[1] = tmp;

  uint32_t h[4] = { H[0], H[1], H[2], H[3] }, w[16], tmp, F;
  for (i = 0; i < 16; ++i)
    w[i] = (block[i * 4]) | (block[i * 4 + 1] << 8) | (block[i * 4 + 2] << 16) | (block[i * 4 + 3] << 24);


  for (i = 0; i < 16; ++i)	//Round 1
  {
    tmp = i, F = (((h[2] ^ h[3]) & (h[1])) ^ h[3]);
    ROTATE_VALUE(0)
  }
  for (i = 0; i < 16; ++i)	//Round 2
  {
    tmp = (1 + 5 * i) % 16, F = ((h[1] ^ h[2]) & (h[3])) ^ h[2];

    ROTATE_VALUE(4)
  }
  for (i = 0; i < 16; ++i)	//Round 3
  {
    tmp = (5 + 3 * i) % 16, F = (h[1] ^ h[2] ^ h[3]);
    ROTATE_VALUE(8)
  }
  for (i = 0; i < 16; ++i)	//Round 4
  {
    tmp = (7 * i) % 16, F = (h[2] ^ (h[1] | (~h[3])));
    ROTATE_VALUE(12)
  }

  H[0] += h[0];
  H[1] += h[1];
  H[2] += h[2];
  H[3] += h[3];

}
void md5Hash(unsigned char *src, uint64_t l, uint32_t * dst)
{
  unsigned char *src_ = src, is_1 = 0;
  uint32_t H[4] = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476 }, i, s = l;

  while (s / 56)
  {
    unsigned char block[64] = { 0 }, i;
    for (i = 0; i < 64 && s; ++i, ++src_, --s)
      block[i] = *src_;
    if (!s && i < 64)
      block[i] = 1 << 7, is_1 = 1;
    md5Block512(block, H);
  }
  {
    unsigned char block[64] = { 0 }, i;
    for (i = 0; i < 64 && s; ++i, ++src_, --s)
      block[i] = *src_;
    if (!is_1)
      block[i] = 1 << 7;
    for (l <<= 3, i = 0; i < 8 && l; ++i, l >>= 8)
      block[56 + i] = l & 0xFF;
    md5Block512(block, H);
  }
  for (i = 0; i < 4; ++i)
    dst[i] = (((H[i]) & 0xFF) << 24),
    dst[i] |= (((H[i] >> (1 * 8)) & 0xFF) << 16),
    dst[i] |= (((H[i] >> (2 * 8)) & 0xFF) << 8),
    dst[i] |= ((H[i] >> (3 * 8)) & 0xFF);

}
void md5HashFile(unsigned char *src, uint32_t * dst)
{
  unsigned char is_1 = 0, block[64] = { 0 }, is_t = 0;
  uint32_t i, H[4] = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476 }, c;
  uint64_t s = 0;

  FILE* file = fopen(src, "r");
  
  if( !file )
    return;
  c = getc(file);
  while( c != EOF || !is_t) 
  {
    for (i = 0; i < 64 && c != EOF; ++i, ++s, c = getc(file))
      block[i] = (unsigned char)c;
    for(uint32_t j = i ; j < 64 ;++j)
      block[j] = 0;
    if (i < 64 && !is_1)
      block[i] = 1 << 7, is_1 = 1;
    if( i < 56 )
    {
      is_t = 1;
      for (uint64_t l = s << 3, i = 0; i < 8 && l; ++i, l >>= 8)
        block[56 + i] = l & 0xFF;
    }
    md5Block512(block, H);
  }
  for (i = 0; i < 4; ++i)
    dst[i] = (((H[i]) & 0xFF) << 24),
    dst[i] |= (((H[i] >> (1 * 8)) & 0xFF) << 16),
    dst[i] |= (((H[i] >> (2 * 8)) & 0xFF) << 8),
    dst[i] |= ((H[i] >> (3 * 8)) & 0xFF);
    
}

/*
        DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
                    Version 2, December 2004 

 Copyright (C) 2004 Sam Hocevar <sam@hocevar.net> 

 Everyone is permitted to copy and distribute verbatim or modified 
 copies of this license document, and changing it is allowed as long 
 as the name is changed. 

            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION 

  0. You just DO WHAT THE FUCK YOU WANT TO.
*/

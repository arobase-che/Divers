/*♡ Copying is an act of love. Please copy.
    
    
  Codé par @che - Implémentation de fonction de hashage SHA1 / Fichier et Chaine
  Licence - WTFPL
*/

#include <stdint.h>
#include "sha1.h"

/* // Fonction d'exemple
#include <stdio.h>

int main(void)
{
  uint32_t dst[5];
  sha1Hash("un", 2 , dst);
  printf("%02X%02X%02X%02X%02X\n", dst[0], dst[1], dst[2], dst[3], dst[4]);
  sha1Hash("ache", 4 , dst);
  printf("%.2X %.2X %.2X %.2X %.2X\n", dst[0], dst[1], dst[2], dst[3], dst[4]);
  sha1HashFile("main.c", dst);
  printf("%.2X %.2X %.2X %.2X %.2X\n", dst[0], dst[1], dst[2], dst[3], dst[4]);
}
*/
#define ROT_L(x, n)   ( (((x) << n) & 0xFFFFFFFF ) | ((x) >> (32 - n)) )


#define K0_19          0x5A827999U
#define K20_39         0x6ED9EBA1U
#define K40_59         0x8F1BBCDCU
#define K60_79         0xCA62C1D6U

#define H0             0x67452301U
#define H1             0xEFCDAB89U
#define H2             0x98BADCFEU
#define H3             0x10325476U
#define H4             0xC3D2E1F0U


uint32_t f(uint32_t x, uint32_t y, uint32_t z, uint32_t t)
{
  switch (t / 20) {
  case 0:
    return ((uint32_t)(x & y) | ((~x) & z));
    // Complement à 1 ou à 2 ?
  case 2:
    return (x & y) | (x & z) | (y & z);

  case 1:
  case 3:
    return x ^ y ^ z;

  }
}
void sha1Block512(unsigned char *block, uint32_t * H)
{
    uint32_t W[80] = {0};
    uint32_t t, a = 0, b = 0, c = 0, d = 0, e = 0;
    for(t = 0; t < 16; ++t)
        W[t]  = ((uint32_t) block[t * 4]) << 24,
        W[t] |= ((uint32_t) block[t * 4 + 1]) << 16,
        W[t] |= ((uint32_t) block[t * 4 + 2]) << 8,
        W[t] |= ((uint32_t) block[t * 4 + 3]);
        
    for (t = 16; t < 80; ++t)
      W[t] = ROT_L(W[t - 3] ^ W[t - 8] ^ W[t - 14] ^ W[t - 16], 1);
    a = H[0], b = H[1], c = H[2], d = H[3], e = H[4];
    for (t = 0; t < 80; ++t)
    {
      uint32_t T = ROT_L(a, 5) + f(b, c, d, t) + e +
                  ((uint32_t[]){ K0_19, K20_39, K40_59, K60_79 })[t / 20] + W[t];
      T &= 0xFFFFFFFF;
      e = d;
      d = c;
      c = ROT_L(b, 30);
      b = a;
      a = T;
    }
    H[0] += a;
    H[1] += b;
    H[2] += c;
    H[3] += d;
    H[4] += e;
  
}
void sha1Hash(unsigned char *src, uint64_t l, uint32_t * dst)
{
  unsigned char block[64] = { 0 }, *src_ = src, is_1 = 0;
  uint32_t H[5] = { H0, H1, H2, H3, H4 }, i;
  uint64_t s = l;

  while (s / 56)
  {
    unsigned char block[64] = { 0 }, i;
    for (i = 0; i < 64 && s; ++i, ++src_, --s)
      block[i] = *src_;
    if (!s && i < 64)
      block[i] = 1 << 7, is_1 = 1;
    sha1Block512(block, H);
  }
  {
    unsigned char block[64] = { 0 }, i;
    for (i = 0; i < 64 && s; ++i, ++src_, --s)
      block[i] = *src_;
    if (!is_1)
      block[i] = 1 << 7;
    for (l <<= 3, i = 0; i < 8 && l; ++i, l >>= 8)
      block[63-i] = l & 0xFF;
    sha1Block512(block, H);
  }

  for(int i = 0 ; i < 5 ;++i)
    dst[i] = H[i];
}
void sha1HashFile(unsigned char *src, uint32_t * dst)
{
  unsigned char is_1 = 0, block[64] = { 0 }, is_t = 0;
  uint32_t i, H[5] = { H0, H1, H2, H3, H4 }, c;
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
        block[63-i] = l & 0xFF;
    }
    sha1Block512(block, H);
  }
  for(int i = 0 ; i < 5 ;++i)
    dst[i] = H[i];
    
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


/*♡ Copying is an act of love. Please copy.
    
    
  Codé par @che - Implémentation du codage Base64 (String & URI)
  Licence - WTFPL
*/

#include "base64.h"

//  Compile avec : gcc base64.c -o base64
/* // Fonction d'exemple 
#include<stdio.h>

int main(void) {
  char chaine[100] = "";
  char dest[100] = "";
  char dest2[100] = "";
  char dest3[100] = "";
  char dest4[100] = "";

  scanf("%99[^\n]s", chaine);

  puts("Codage BASE64 :"); 
  to_base64(dest, chaine);
  puts(dest);
  puts("Codage BASE64 (URI) :"); 
  to_URI_base64(dest2, chaine);
  puts(dest2);
  puts("Décodage BASE64 :"); 
  from_base64(dest3, dest);
  puts(dest3);
  puts("Décodage BASE64 (URI) :"); 
  from_URI_base64(dest4, dest2);
  puts(dest4);
  
  return 0;
}*/


#ifndef HEADER_NAME
#define HEADER_NAME  base64
#define HTO          to_base64
#define HFROM        from_base64
#define HALPHA       alpha_base64
#define HDEC         dec_base64
#define HURITO       to_URI_base64
#define HURIFROM     from_URI_base64
#else
#error "Redefinition HEADER_NAME"
#endif

static const char HALPHA[] =  "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";


static int HDEC[] = {
  ['A'] = 0,['B'] = 1,['C'] = 2,['D'] = 3,['E'] = 4,
  ['F'] = 5,['G'] = 6,['H'] = 7,['I'] = 8,['J'] = 9,
  ['K'] = 10,['L'] = 11,['M'] = 12,['N'] = 13,['O'] = 14,
  ['P'] = 15,['Q'] = 16,['R'] = 17,['S'] = 18,['T'] = 19,
  ['U'] = 20,['V'] = 21,['W'] = 22,['X'] = 23,['Y'] = 24,
  ['Z'] = 25,['a'] = 26,['b'] = 27,['c'] = 28,['d'] = 29,
  ['e'] = 30,['f'] = 31,['g'] = 32,['h'] = 33,['i'] = 34,
  ['j'] = 35,['k'] = 36,['l'] = 37,['m'] = 38,['n'] = 39,
  ['o'] = 40,['p'] = 41,['q'] = 42,['r'] = 43,['s'] = 44,
  ['t'] = 45,['u'] = 46,['v'] = 47,['w'] = 48,['x'] = 49,
  ['y'] = 50,['z'] = 51,['0'] = 52,['1'] = 53,['2'] = 54,
  ['3'] = 55,['4'] = 56,['5'] = 57,['6'] = 58,['7'] = 59,
  ['8'] = 60,['9'] = 61,['+'] = 62,['/'] = 63,['='] = 64
};


#include "base.h"

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


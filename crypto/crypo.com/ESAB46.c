/*♡ Copying is an act of love. Please copy.
    
    
  Codé par @che - Implémentation du codage ESAB46 (String & URI)
  Licence - WTFPL
*/

#include "ESAB46.h"

// Compile avec gcc ESAB46.c -o ESAB46
 //Fonction d'exemple
#include<stdio.h>

int main(void) {
  char chaine[100] = "";
  char dest[100] = "";
  char dest2[100] = "";
  char dest3[100] = "";
  char dest4[100] = "";

  scanf("%99[^\n]s", chaine);

  puts("Codage ESAB46 :"); 
  to_ESAB46(dest, chaine);
  puts(dest);
  puts("Codage ESAB46 (URI) :"); 
  to_URI_ESAB46(dest2, chaine);
  puts(dest2);
  puts("Décodage ESAB46 :"); 
  from_ESAB46(dest3, dest);
  puts(dest3);
  puts("Décodage ESAB46 (URI) :"); 
  from_URI_ESAB46(dest4, dest2);
  puts(dest4);
  
  return 0;
}

#ifndef HEADER_NAME
#define HEADER_NAME  ESAB46
#define HTO          to_ESAB46
#define HFROM        from_ESAB46
#define HURITO       to_URI_ESAB46
#define HURIFROM     from_URI_ESAB46
#define HALPHA       alpha_ESAB46
#define HDEC         dec_ESAB46
#else
#error "Redefinition HEADER_NAME"
#endif



static const char HALPHA [] =  "ABCDqrs456tuvNOPwxyz012KLM3789=+QRSTUVWXYZabcdefghijklmnopEFGHIJ/";

static int HDEC[] = {
['A'] = 0, ['B'] = 1, ['C'] = 2, ['D'] = 3, ['q'] = 4, 
['r'] = 5, ['s'] = 6, ['4'] = 7, ['5'] = 8, ['6'] = 9, 
['t'] = 10, ['u'] = 11, ['v'] = 12, ['N'] = 13, ['O'] = 14, 
['P'] = 15, ['w'] = 16, ['x'] = 17, ['y'] = 18, ['z'] = 19, 
['0'] = 20, ['1'] = 21, ['2'] = 22, ['K'] = 23, ['L'] = 24, 
['M'] = 25, ['3'] = 26, ['7'] = 27, ['8'] = 28, ['9'] = 29, 
['='] = 30, ['+'] = 31, ['Q'] = 32, ['R'] = 33, ['S'] = 34, 
['T'] = 35, ['U'] = 36, ['V'] = 37, ['W'] = 38, ['X'] = 39, 
['Y'] = 40, ['Z'] = 41, ['a'] = 42, ['b'] = 43, ['c'] = 44, 
['d'] = 45, ['e'] = 46, ['f'] = 47, ['g'] = 48, ['h'] = 49, 
['i'] = 50, ['j'] = 51, ['k'] = 52, ['l'] = 53, ['m'] = 54, 
['n'] = 55, ['o'] = 56, ['p'] = 57, ['E'] = 58, ['F'] = 59, 
['G'] = 60, ['H'] = 61, ['I'] = 62, ['J'] = 63, ['/'] = 64};


  
  
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


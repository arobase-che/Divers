/*♡ Copying is an act of love. Please copy.
    
    
  Codé par @che - Implémentation du codage Atom128 (String & URI)
  Licence - WTFPL
*/

#include "feron74.h"

// Compile avec gcc feron74.c -o feron74
/* //Fonction d'exemple
#include<stdio.h>

int main(void) {
  char chaine[100] = "";
  char dest[100] = "";
  char dest2[100] = "";
  char dest3[100] = "";
  char dest4[100] = "";

  scanf("%99[^\n]s", chaine);

  puts("Codage FERON74 :"); 
  to_feron74(dest, chaine);
  puts(dest);
  puts("Codage FERON74 (URI) :"); 
  to_URI_feron74(dest2, chaine);
  puts(dest2);
  puts("Décodage FERON74 :"); 
  from_feron74(dest3, dest);
  puts(dest3);
  puts("Décodage FERON74 (URI) :"); 
  from_URI_feron74(dest4, dest2);
  puts(dest4);
  
  return 0;
}*/

#ifndef HEADER_NAME
#define HEADER_NAME  feron74
#define HTO          to_feron74
#define HFROM        from_feron74
#define HURITO       to_URI_feron74
#define HURIFROM     from_URI_feron74
#define HALPHA       alpha_feron74
#define HDEC         dec_feron74
#else
#error "Redefinition HEADER_NAME"
#endif



static const char HALPHA [] =  "75XYTabcS/UVWdefADqr6RuvN8PBCsQtwx2KLyz+OM3Hk9ghi01ZFlmnjopE=GIJ4";

static int HDEC[] = {
['7'] = 0, ['5'] = 1, ['X'] = 2, ['Y'] = 3, ['T'] = 4, 
['a'] = 5, ['b'] = 6, ['c'] = 7, ['S'] = 8, ['/'] = 9, 
['U'] = 10, ['V'] = 11, ['W'] = 12, ['d'] = 13, ['e'] = 14, 
['f'] = 15, ['A'] = 16, ['D'] = 17, ['q'] = 18, ['r'] = 19, 
['6'] = 20, ['R'] = 21, ['u'] = 22, ['v'] = 23, ['N'] = 24, 
['8'] = 25, ['P'] = 26, ['B'] = 27, ['C'] = 28, ['s'] = 29, 
['Q'] = 30, ['t'] = 31, ['w'] = 32, ['x'] = 33, ['2'] = 34, 
['K'] = 35, ['L'] = 36, ['y'] = 37, ['z'] = 38, ['+'] = 39, 
['O'] = 40, ['M'] = 41, ['3'] = 42, ['H'] = 43, ['k'] = 44, 
['9'] = 45, ['g'] = 46, ['h'] = 47, ['i'] = 48, ['0'] = 49, 
['1'] = 50, ['Z'] = 51, ['F'] = 52, ['l'] = 53, ['m'] = 54, 
['n'] = 55, ['j'] = 56, ['o'] = 57, ['p'] = 58, ['E'] = 59, 
['='] = 60, ['G'] = 61, ['I'] = 62, ['J'] = 63, ['4'] = 64};


  
  
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


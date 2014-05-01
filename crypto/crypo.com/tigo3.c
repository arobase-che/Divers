/*♡ Copying is an act of love. Please copy.
    
    
  Codé par @che - Implémentation du codage Atom128 (String & URI)
  Licence - WTFPL
*/

#include "tigo3.h"

// Compile avec gcc tigo3.c -o tigo3
/* //Fonction d'exemple
#include<stdio.h>

int main(void) {
  char chaine[100] = "";
  char dest[100] = "";
  char dest2[100] = "";
  char dest3[100] = "";
  char dest4[100] = "";

  scanf("%99[^\n]s", chaine);

  puts("Codage TIGO3 :"); 
  to_tigo3(dest, chaine);
  puts(dest);
  puts("Codage TIGO3 (URI) :"); 
  to_URI_tigo3(dest2, chaine);
  puts(dest2);
  puts("Décodage TIGO3 :"); 
  from_tigo3(dest3, dest);
  puts(dest3);
  puts("Décodage TIGO3 (URI) :"); 
  from_URI_tigo3(dest4, dest2);
  puts(dest4);
  
  return 0;
}*/

#ifndef HEADER_NAME
#define HEADER_NAME  tigo3
#define HTO          to_tigo3
#define HFROM        from_tigo3
#define HURITO       to_URI_tigo3
#define HURIFROM     from_URI_tigo3
#define HALPHA       alpha_tigo3
#define HDEC         dec_tigo3
#else
#error "Redefinition HEADER_NAME"
#endif



static const char HALPHA [] =  "FrsxyzA8VtuvwDEqWZ/1+4klm67=cBCa5Ybdef0g2hij9nopMNO3GHIRSTJKLPQUX";

static int HDEC[] = {
['F'] = 0, ['r'] = 1, ['s'] = 2, ['x'] = 3, ['y'] = 4, 
['z'] = 5, ['A'] = 6, ['8'] = 7, ['V'] = 8, ['t'] = 9, 
['u'] = 10, ['v'] = 11, ['w'] = 12, ['D'] = 13, ['E'] = 14, 
['q'] = 15, ['W'] = 16, ['Z'] = 17, ['/'] = 18, ['1'] = 19, 
['+'] = 20, ['4'] = 21, ['k'] = 22, ['l'] = 23, ['m'] = 24, 
['6'] = 25, ['7'] = 26, ['='] = 27, ['c'] = 28, ['B'] = 29, 
['C'] = 30, ['a'] = 31, ['5'] = 32, ['Y'] = 33, ['b'] = 34, 
['d'] = 35, ['e'] = 36, ['f'] = 37, ['0'] = 38, ['g'] = 39, 
['2'] = 40, ['h'] = 41, ['i'] = 42, ['j'] = 43, ['9'] = 44, 
['n'] = 45, ['o'] = 46, ['p'] = 47, ['M'] = 48, ['N'] = 49, 
['O'] = 50, ['3'] = 51, ['G'] = 52, ['H'] = 53, ['I'] = 54, 
['R'] = 55, ['S'] = 56, ['T'] = 57, ['J'] = 58, ['K'] = 59, 
['L'] = 60, ['P'] = 61, ['Q'] = 62, ['U'] = 63, ['X'] = 64};


  
  
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


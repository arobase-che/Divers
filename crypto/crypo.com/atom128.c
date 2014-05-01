/*♡ Copying is an act of love. Please copy.
    
    
  Codé par @che - Implémentation du codage Atom128 (String & URI)
  Licence - WTFPL
*/

#include "atom128.h"

// Compile avec gcc atom128.c -o atom128
/* //Fonction d'exemple
#include<stdio.h>

int main(void) {
  char chaine[100] = "";
  char dest[100] = "";
  char dest2[100] = "";
  char dest3[100] = "";
  char dest4[100] = "";

  scanf("%99[^\n]s", chaine);

  puts("Codage ATOM128 :"); 
  to_atom128(dest, chaine);
  puts(dest);
  puts("Codage ATOM128 (URI) :"); 
  to_URI_atom128(dest2, chaine);
  puts(dest2);
  puts("Décodage ATOM128 :"); 
  from_atom128(dest3, dest);
  puts(dest3);
  puts("Décodage ATOM128 (URI) :"); 
  from_URI_atom128(dest4, dest2);
  puts(dest4);
  
  return 0;
}*/

#ifndef HEADER_NAME
#define HEADER_NAME  atom128
#define HTO          to_atom128
#define HFROM        from_atom128
#define HURITO       to_URI_atom128
#define HURIFROM     from_URI_atom128
#define HALPHA       alpha_atom128
#define HDEC         dec_atom128
#else
#error "Redefinition HEADER_NAME"
#endif



static const char HALPHA [] =  "/128GhIoPQROSTeUbADfgHijKLM+n0pFWXY456xyzB7=39VaqrstJklmNuZvwcdEC";

static int HDEC[] = {
['/'] = 0, ['1'] = 1, ['2'] = 2, ['8'] = 3, ['G'] = 4, 
['h'] = 5, ['I'] = 6, ['o'] = 7, ['P'] = 8, ['Q'] = 9, 
['R'] = 10, ['O'] = 11, ['S'] = 12, ['T'] = 13, ['e'] = 14, 
['U'] = 15, ['b'] = 16, ['A'] = 17, ['D'] = 18, ['f'] = 19, 
['g'] = 20, ['H'] = 21, ['i'] = 22, ['j'] = 23, ['K'] = 24, 
['L'] = 25, ['M'] = 26, ['+'] = 27, ['n'] = 28, ['0'] = 29, 
['p'] = 30, ['F'] = 31, ['W'] = 32, ['X'] = 33, ['Y'] = 34, 
['4'] = 35, ['5'] = 36, ['6'] = 37, ['x'] = 38, ['y'] = 39, 
['z'] = 40, ['B'] = 41, ['7'] = 42, ['='] = 43, ['3'] = 44, 
['9'] = 45, ['V'] = 46, ['a'] = 47, ['q'] = 48, ['r'] = 49, 
['s'] = 50, ['t'] = 51, ['J'] = 52, ['k'] = 53, ['l'] = 54, 
['m'] = 55, ['N'] = 56, ['u'] = 57, ['Z'] = 58, ['v'] = 59, 
['w'] = 60, ['c'] = 61, ['d'] = 62, ['E'] = 63, ['C'] = 64};

  
  
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


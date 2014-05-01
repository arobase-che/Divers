/*♡ Copying is an act of love. Please copy.
    
    
  Codé par @che - Implémentation du codage Atom128 (String & URI)
  Licence - WTFPL
*/

#include "tripo5.h"

// Compile avec gcc tripo5.c -o tripo5
/* //Fonction d'exemple
#include<stdio.h>

int main(void) {
  char chaine[100] = "";
  char dest[100] = "";
  char dest2[100] = "";
  char dest3[100] = "";
  char dest4[100] = "";

  scanf("%99[^\n]s", chaine);

  puts("Codage TRIPO5 :"); 
  to_tripo5(dest, chaine);
  puts(dest);
  puts("Codage TRIPO5 (URI) :"); 
  to_URI_tripo5(dest2, chaine);
  puts(dest2);
  puts("Décodage TRIPO5 :"); 
  from_tripo5(dest3, dest);
  puts(dest3);
  puts("Décodage TRIPO5 (URI) :"); 
  from_URI_tripo5(dest4, dest2);
  puts(dest4);
  
  return 0;
}*/

#ifndef HEADER_NAME
#define HEADER_NAME  tripo5
#define HTO          to_tripo5
#define HFROM        from_tripo5
#define HURITO       to_URI_tripo5
#define HURIFROM     from_URI_tripo5
#define HALPHA       alpha_tripo5
#define HDEC         dec_tripo5
#else
#error "Redefinition HEADER_NAME"
#endif



static const char HALPHA [] =  "ghijopE+G78lmnIJQRXY=abcS/UVWdefABCs456tDqruvNOPwx2KLyz01M3Hk9ZFT";

static int HDEC[] = {
['g'] = 0, ['h'] = 1, ['i'] = 2, ['j'] = 3, ['o'] = 4, 
['p'] = 5, ['E'] = 6, ['+'] = 7, ['G'] = 8, ['7'] = 9, 
['8'] = 10, ['l'] = 11, ['m'] = 12, ['n'] = 13, ['I'] = 14, 
['J'] = 15, ['Q'] = 16, ['R'] = 17, ['X'] = 18, ['Y'] = 19, 
['='] = 20, ['a'] = 21, ['b'] = 22, ['c'] = 23, ['S'] = 24, 
['/'] = 25, ['U'] = 26, ['V'] = 27, ['W'] = 28, ['d'] = 29, 
['e'] = 30, ['f'] = 31, ['A'] = 32, ['B'] = 33, ['C'] = 34, 
['s'] = 35, ['4'] = 36, ['5'] = 37, ['6'] = 38, ['t'] = 39, 
['D'] = 40, ['q'] = 41, ['r'] = 42, ['u'] = 43, ['v'] = 44, 
['N'] = 45, ['O'] = 46, ['P'] = 47, ['w'] = 48, ['x'] = 49, 
['2'] = 50, ['K'] = 51, ['L'] = 52, ['y'] = 53, ['z'] = 54, 
['0'] = 55, ['1'] = 56, ['M'] = 57, ['3'] = 58, ['H'] = 59, 
['k'] = 60, ['9'] = 61, ['Z'] = 62, ['F'] = 63, ['T'] = 64};


  
  
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


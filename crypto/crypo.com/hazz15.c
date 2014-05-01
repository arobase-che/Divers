/*♡ Copying is an act of love. Please copy.
    
    
  Codé par @che - Implémentation du codage Atom128 (String & URI)
  Licence - WTFPL
*/

#include "hazz15.h"

// Compile avec gcc hazz15.c -o hazz15
/* //Fonction d'exemple
#include<stdio.h>

int main(void) {
  char chaine[100] = "";
  char dest[100] = "";
  char dest2[100] = "";
  char dest3[100] = "";
  char dest4[100] = "";

  scanf("%99[^\n]s", chaine);

  puts("Codage HAZZ15 :"); 
  to_hazz15(dest, chaine);
  puts(dest);
  puts("Codage HAZZ15 (URI) :"); 
  to_URI_hazz15(dest2, chaine);
  puts(dest2);
  puts("Décodage HAZZ15 :"); 
  from_hazz15(dest3, dest);
  puts(dest3);
  puts("Décodage HAZZ15 (URI) :"); 
  from_URI_hazz15(dest4, dest2);
  puts(dest4);
  
  return 0;
}*/

#ifndef HEADER_NAME
#define HEADER_NAME  hazz15
#define HTO          to_hazz15
#define HFROM        from_hazz15
#define HURITO       to_URI_hazz15
#define HURIFROM     from_URI_hazz15
#define HALPHA       alpha_hazz15
#define HDEC         dec_hazz15
#else
#error "Redefinition HEADER_NAME"
#endif



static const char HALPHA [] =  "HNO4klm6ij9n+J2hyf0gzA8uvwDEq3X1Q7ZKeFrWcVTts/MRGYbdxSo=ILaUpPBC5";

static int HDEC[] = {
['H'] = 0, ['N'] = 1, ['O'] = 2, ['4'] = 3, ['k'] = 4, 
['l'] = 5, ['m'] = 6, ['6'] = 7, ['i'] = 8, ['j'] = 9, 
['9'] = 10, ['n'] = 11, ['+'] = 12, ['J'] = 13, ['2'] = 14, 
['h'] = 15, ['y'] = 16, ['f'] = 17, ['0'] = 18, ['g'] = 19, 
['z'] = 20, ['A'] = 21, ['8'] = 22, ['u'] = 23, ['v'] = 24, 
['w'] = 25, ['D'] = 26, ['E'] = 27, ['q'] = 28, ['3'] = 29, 
['X'] = 30, ['1'] = 31, ['Q'] = 32, ['7'] = 33, ['Z'] = 34, 
['K'] = 35, ['e'] = 36, ['F'] = 37, ['r'] = 38, ['W'] = 39, 
['c'] = 40, ['V'] = 41, ['T'] = 42, ['t'] = 43, ['s'] = 44, 
['/'] = 45, ['M'] = 46, ['R'] = 47, ['G'] = 48, ['Y'] = 49, 
['b'] = 50, ['d'] = 51, ['x'] = 52, ['S'] = 53, ['o'] = 54, 
['='] = 55, ['I'] = 56, ['L'] = 57, ['a'] = 58, ['U'] = 59, 
['p'] = 60, ['P'] = 61, ['B'] = 62, ['C'] = 63, ['5'] = 64};


  
  
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


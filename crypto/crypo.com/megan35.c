/*♡ Copying is an act of love. Please copy.
    
    
  Codé par @che - Implémentation du codage Megan35 (String & URI)
  Licence - WTFPL
*/

#include "megan35.h"

// Compile avec gcc megan35.c -o megan35
 //Fonction d'exemple
#include<stdio.h>

int main(void) {
  char chaine[100] = "";
  char dest[100] = "";
  char dest2[100] = "";
  char dest3[100] = "";
  char dest4[100] = "";

  scanf("%99[^\n]s", chaine);

  puts("Codage MEGAN35 :"); 
  to_megan35(dest, chaine);
  puts(dest);
  puts("Codage MEGAN35 (URI) :"); 
  to_URI_megan35(dest2, chaine);
  puts(dest2);
  puts("Décodage MEGAN35 :"); 
  from_megan35(dest3, dest);
  puts(dest3);
  puts("Décodage MEGAN35 (URI) :"); 
  from_URI_megan35(dest4, dest2);
  puts(dest4);
  
  return 0;
}

#ifndef HEADER_NAME
#define HEADER_NAME  megan35
#define HTO          to_megan35
#define HFROM        from_megan35
#define HURITO       to_URI_megan35
#define HURIFROM     from_URI_megan35
#define HALPHA       alpha_megan35
#define HDEC         dec_megan35
#else
#error "Redefinition HEADER_NAME"
#endif



static const char HALPHA [] =  "3GHIJKLMNOPQRSTUb=cdefghijklmnopWXYZ/12+406789VaqrstuvwxyzABCDEF5";

static int HDEC[] = {
['3'] = 0, ['G'] = 1, ['H'] = 2, ['I'] = 3, ['J'] = 4, 
['K'] = 5, ['L'] = 6, ['M'] = 7, ['N'] = 8, ['O'] = 9, 
['P'] = 10, ['Q'] = 11, ['R'] = 12, ['S'] = 13, ['T'] = 14, 
['U'] = 15, ['b'] = 16, ['='] = 17, ['c'] = 18, ['d'] = 19, 
['e'] = 20, ['f'] = 21, ['g'] = 22, ['h'] = 23, ['i'] = 24, 
['j'] = 25, ['k'] = 26, ['l'] = 27, ['m'] = 28, ['n'] = 29, 
['o'] = 30, ['p'] = 31, ['W'] = 32, ['X'] = 33, ['Y'] = 34, 
['Z'] = 35, ['/'] = 36, ['1'] = 37, ['2'] = 38, ['+'] = 39, 
['4'] = 40, ['0'] = 41, ['6'] = 42, ['7'] = 43, ['8'] = 44, 
['9'] = 45, ['V'] = 46, ['a'] = 47, ['q'] = 48, ['r'] = 49, 
['s'] = 50, ['t'] = 51, ['u'] = 52, ['v'] = 53, ['w'] = 54, 
['x'] = 55, ['y'] = 56, ['z'] = 57, ['A'] = 58, ['B'] = 59, 
['C'] = 60, ['D'] = 61, ['E'] = 62, ['F'] = 63, ['5'] = 64};


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


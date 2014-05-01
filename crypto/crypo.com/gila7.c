/*♡ Copying is an act of love. Please copy.
    
    
  Codé par @che - Implémentation du codage Atom128 (String & URI)
  Licence - WTFPL
*/

#include "gila7.h"

// Compile avec gcc gila7.c -o gila7
/* //Fonction d'exemple
#include<stdio.h>

int main(void) {
  char chaine[100] = "";
  char dest[100] = "";
  char dest2[100] = "";
  char dest3[100] = "";
  char dest4[100] = "";

  scanf("%99[^\n]s", chaine);

  puts("Codage GILA7 :"); 
  to_gila7(dest, chaine);
  puts(dest);
  puts("Codage GILA7 (URI) :"); 
  to_URI_gila7(dest2, chaine);
  puts(dest2);
  puts("Décodage GILA7 :"); 
  from_gila7(dest3, dest);
  puts(dest3);
  puts("Décodage GILA7 (URI) :"); 
  from_URI_gila7(dest4, dest2);
  puts(dest4);
  
  return 0;
}*/

#ifndef HEADER_NAME
#define HEADER_NAME  gila7
#define HTO          to_gila7
#define HFROM        from_gila7
#define HURITO       to_URI_gila7
#define HURIFROM     from_URI_gila7
#define HALPHA       alpha_gila7
#define HDEC         dec_gila7
#else
#error "Redefinition HEADER_NAME"
#endif



static const char HALPHA [] =  "7ZSTJK+W=cVtBCasyf0gzA8uvwDEq3XH/1RMNOILPQU4klm65YbdeFrx2hij9nopG";

static int HDEC[] = {
['7'] = 0, ['Z'] = 1, ['S'] = 2, ['T'] = 3, ['J'] = 4, 
['K'] = 5, ['+'] = 6, ['W'] = 7, ['='] = 8, ['c'] = 9, 
['V'] = 10, ['t'] = 11, ['B'] = 12, ['C'] = 13, ['a'] = 14, 
['s'] = 15, ['y'] = 16, ['f'] = 17, ['0'] = 18, ['g'] = 19, 
['z'] = 20, ['A'] = 21, ['8'] = 22, ['u'] = 23, ['v'] = 24, 
['w'] = 25, ['D'] = 26, ['E'] = 27, ['q'] = 28, ['3'] = 29, 
['X'] = 30, ['H'] = 31, ['/'] = 32, ['1'] = 33, ['R'] = 34, 
['M'] = 35, ['N'] = 36, ['O'] = 37, ['I'] = 38, ['L'] = 39, 
['P'] = 40, ['Q'] = 41, ['U'] = 42, ['4'] = 43, ['k'] = 44, 
['l'] = 45, ['m'] = 46, ['6'] = 47, ['5'] = 48, ['Y'] = 49, 
['b'] = 50, ['d'] = 51, ['e'] = 52, ['F'] = 53, ['r'] = 54, 
['x'] = 55, ['2'] = 56, ['h'] = 57, ['i'] = 58, ['j'] = 59, 
['9'] = 60, ['n'] = 61, ['o'] = 62, ['p'] = 63, ['G'] = 64};



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


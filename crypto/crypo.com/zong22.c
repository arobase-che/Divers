/*♡ Copying is an act of love. Please copy.
    
    
  Codé par @che - Implémentation du codage Atom128 (String & URI)
  Licence - WTFPL
*/

#include "zong22.h"

// Compile avec gcc zong22.c -o zong22
 //Fonction d'exemple
#include<stdio.h>

int main(void) {
  char chaine[100] = "";
  char dest[100] = "";
  char dest2[100] = "";
  char dest3[100] = "";
  char dest4[100] = "";

  scanf("%99[^\n]s", chaine);

  puts("Codage ZONG22 :"); 
  to_zong22(dest, chaine);
  puts(dest);
  puts("Codage ZONG22 (URI) :"); 
  to_URI_zong22(dest2, chaine);
  puts(dest2);
  puts("Décodage ZONG22 :"); 
  from_zong22(dest3, dest);
  puts(dest3);
  puts("Décodage ZONG22 (URI) :"); 
  from_URI_zong22(dest4, dest2);
  puts(dest4);
  
  return 0;
}

#ifndef HEADER_NAME
#define HEADER_NAME  zong22
#define HTO          to_zong22
#define HFROM        from_zong22
#define HURITO       to_URI_zong22
#define HURIFROM     from_URI_zong22
#define HALPHA       alpha_zong22
#define HDEC         dec_zong22
#else
#error "Redefinition HEADER_NAME"
#endif



static const char HALPHA [] =  "ZKj9n+yf0wDVX1s/5YbdxSo=ILaUpPBCHg8uvNO4klm6iJGhQ7eFrWczAMEq3RTt2";

static int HDEC[] = {
['Z'] = 0, ['K'] = 1, ['j'] = 2, ['9'] = 3, ['n'] = 4, 
['+'] = 5, ['y'] = 6, ['f'] = 7, ['0'] = 8, ['w'] = 9, 
['D'] = 10, ['V'] = 11, ['X'] = 12, ['1'] = 13, ['s'] = 14, 
['/'] = 15, ['5'] = 16, ['Y'] = 17, ['b'] = 18, ['d'] = 19, 
['x'] = 20, ['S'] = 21, ['o'] = 22, ['='] = 23, ['I'] = 24, 
['L'] = 25, ['a'] = 26, ['U'] = 27, ['p'] = 28, ['P'] = 29, 
['B'] = 30, ['C'] = 31, ['H'] = 32, ['g'] = 33, ['8'] = 34, 
['u'] = 35, ['v'] = 36, ['N'] = 37, ['O'] = 38, ['4'] = 39, 
['k'] = 40, ['l'] = 41, ['m'] = 42, ['6'] = 43, ['i'] = 44, 
['J'] = 45, ['G'] = 46, ['h'] = 47, ['Q'] = 48, ['7'] = 49, 
['e'] = 50, ['F'] = 51, ['r'] = 52, ['W'] = 53, ['c'] = 54, 
['z'] = 55, ['A'] = 56, ['M'] = 57, ['E'] = 58, ['q'] = 59, 
['3'] = 60, ['R'] = 61, ['T'] = 62, ['t'] = 63, ['2'] = 64};


  
  
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


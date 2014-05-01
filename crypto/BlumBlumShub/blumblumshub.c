/*♡ Copying is an act of love. Please copy.
    
    
  Codé par @che - Implémentation de fonction de hashage MD5 / Fichier et Chaine
  Licence - WTFPL
*/

#include "blumblumshub.h"
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

// Compile avec : gcc blumblumshub.c -o bbs
 // Fonction d'exemple 

#include <stdio.h>

int main(void) {
  // Ici, les bits seront toujours différent
  init_BBS();
  printf("%d", blumblumshub(0));
  printf("%d", blumblumshub(0));
  printf("%d", blumblumshub(0));
  printf("%d", blumblumshub(0));
  puts("");
  // Ici, les bits seront toujours les mêmes
  blumblumshub(255); // On initialise avec une même graine
  printf("%d", blumblumshub(0));
  printf("%d", blumblumshub(0));
  printf("%d", blumblumshub(0));
  printf("%d", blumblumshub(0));
  puts("");
}

int pgcd( unsigned a, unsigned b) {
  return a ? pgcd(b%a, a) : b;
}
size_t sqrtInt(size_t a)
{
  size_t p = 1, s = 1, s2 = 4;
  for( 1; !(s <= a && a < s2) ; ++p)
  {
    s = s2;
    s2 += 2*(p+1)-1;
  }
  return p;
}
int isPrime(size_t a) {
   size_t tmp = sqrtInt(a);
   static size_t Sqrt = 0;
   static int* tab = NULL;
   if( Sqrt < tmp) {
     Sqrt = tmp;
     int isComp = 0;
     if( tab ) free(tab);
     tab = calloc( Sqrt+1, sizeof *tab);

     if( !tab ) return -1;
     for( size_t i = 2  ;  i <= Sqrt ; i++) {
       if( tab[i] )
         continue;
       if ( a % i == 0) {
         isComp = 1;
         break;
       }
       for(int j = i+i ; j <= Sqrt ; j+=i)
         tab[j] = 1;
     }
     return !isComp;
   }
   for(int i = 2 ; i < Sqrt ; i++ )
     if( tab[i] )
       continue;
     else if( a % i == 0 )
       return 0;
   return 1;
}
size_t hrand() {
  size_t a = rand();
  for( ; isPrime(a) == 0 ; a++);
  return a;
}
char blumblumshub( size_t seed ) {
  static uint64_t sseed = 0, p, q;
  if( seed ) {
    sseed = seed;
    s:
    do (p = hrand()), (q = hrand()); while ( pgcd(q-1, p-1) == 2 || p%4 != 3 || q%4!=3);
    if( q == p)
      goto s;
  }
  sseed = (sseed*sseed)%(p*q);
  return sseed%2;
}
void init_BBS(void) {
  srand(time(NULL));
  blumblumshub(rand());
}


/*♡ Copying is an act of love. Please copy.
    
    
  Codé par @che - Implémentation de fonction de chiffrement DES - Bloc de 64bits
  Licence - WTFPL
*/

#include "des.h"

// Compile avec : gcc des.c
// Fonction d'exemple

#include <stdio.h>
int main (void) 
{
  unsigned char message[8] = {1, 35, 69, 103, 137, 171, 205, 239}, out[8] = {0};
  unsigned char key[8] = "Acheehca";
  for(int i = 0  ; i < 8 ; i++)
    printf("%.2X", message[i]);
  puts("");
  
  DES_64_enc(message, key, out);
  for(int i = 0  ; i < 8 ; i++)
    printf("%.2X", out[i]);
  puts("");
  
  DES_64_dec(out, key, message);
  for(int i = 0  ; i < 8 ; i++)
    printf("%.2X", message[i]);
  puts("");
  
  return 0;	
}



typedef union block block;
union block
{
	unsigned char D[8];
	struct 
	{
    unsigned	char G[4], D[4];
	}d;
};

int CP1[8][7] = {{57, 49, 41, 33, 25, 17,  9},
               { 1, 58, 50, 42, 34, 26, 18},
               {10,  2, 59, 51, 43, 35, 27},
               {19, 11,  3, 60, 52, 44, 36},
               {63, 55, 47, 39, 31, 23, 15},
               { 7, 62, 54, 46, 38, 30, 22},
               {14,  6, 61, 53, 45, 37, 29},
               {21, 13,  5, 28, 20, 12,  4}};

int CP2[8][6] = {{14, 17, 11, 24,  1,  5},
               { 3, 28, 15,  6, 21, 10},
               {23, 19, 12,  4, 26,  8},
               {16,  7, 27, 20, 13,  2},
               {41, 52, 31, 37, 47, 55},
               {30, 40, 51, 45, 33, 48},
               {44, 49, 39, 56, 34, 53},
               {46, 42, 50, 36, 29, 32}};


int tabS[8][4][16]={{{14,  4,13, 1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9, 0,  7},
                    { 0, 15, 7, 4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5, 3,  8},
                    { 4,  1,14, 8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10, 5,  0},
                    {15, 12, 8, 2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0, 6, 13}},
               {{15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10},
               { 3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5},
               { 0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15},
               {13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9}},

               {{10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8},
               {13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1},
               {13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7},
               { 1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12}},

               {{ 7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15},
               {13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9},
               {10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4},
               { 3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14}},
              
               {{ 2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9},
               {14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6},
               { 4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14},
               {11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3}},
               
               {{12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11},
               {10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8},
               { 9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6},
               { 4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13}},
               
               {{ 4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1},
               {13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6},
               { 1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2},
               { 6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12}},
               
               {{13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7},
               { 1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2},
               { 7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8},
               { 2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11}}};

int pPerm[8][4] = {{16,  7, 20, 21},
                   {29, 12, 28, 17},
                   { 1, 15, 23, 26},
                   { 5, 18, 31, 10},
                   { 2,  8, 24, 14},
                   {32, 27,  3,  9},
                   {19, 13, 30,  6},
                   {22, 11,  4, 25}};
int fPerm[8][8]= {{40,  8, 48, 16, 56, 24, 64, 32},
                  {39,  7, 47, 15, 55, 23, 63, 31},
                  {38,  6, 46, 14, 54, 22, 62, 30},
                  {37,  5, 45, 13, 53, 21, 61, 29},
                  {36,  4, 44, 12, 52, 20, 60, 28},
                  {35,  3, 43, 11, 51, 19, 59, 27},
                  {34,  2, 42, 10, 50, 18, 58, 26},
                  {33,  1, 41,  9, 49, 17, 57, 25}};
unsigned char subkeys[16][48] = {{0}};

int nbit(const int nb,const  void* t)
{
	int i,j;int g;
	for(j=0,g=128;j<nb%8;j++)g/=2;
	return !!(*((char*)t + (nb/8)) & g);
}
int setbit(const int nb, void* t,const  int bit)
{
	if(!bit)return 0;
	int i,j;int g;
	for(j=0,g=128;j<nb%8;j++)g/=2;
	return !!(*((char*)t + (nb/8)) |= g);
}

void initSubKeys2(const unsigned char keyInit[]) {
	unsigned char keyPerm[8] = {0};
	for(int i = 0 ; i < 8; i++) {
	  int a = 0;
	  for( int j = 0 ; j < 7 ; ++j)
	    a+=nbit(CP1[i][j]-1, keyInit),a<<=1;
	  a>>=1;
	  keyPerm[i] = a;
	}
	
	unsigned char C[16][4] = {0};
	unsigned char D[16][4] = {0};
	
  { // C
	  int tmp = (keyPerm[0]&(1<<6))>>6;
	  for(int i = 0 ; i < sizeof C[0] ; i++) {
	    int a = keyPerm[i];
	    a<<=1;
	    a&=127;
      a+=((keyPerm[i+1]&(1<<6))>>6);
	    C[0][i] = a;
	  }
	  C[0][sizeof C[0]-1] ^= tmp;
  }
  { // D
	  int tmp = (keyPerm[4]&(1<<6))>>6;
	  for(int i = 0 ; i < sizeof D[0] ; i++) {
	    int a = keyPerm[4+i];
	    a<<=1;
	    a&=127;
      a+=((keyPerm[4+i+1]&(1<<6))>>6);
	    D[0][i] = a;
	  }
	  D[0][sizeof D[0]-1] ^= tmp;
  }
  for(int i = 1, suite = 16254 ; i < 16 ; i++, suite>>=1) {
    for(int j = (suite&1)+1; j > 0 ; j--) {
	    int tmp = (C[i-1+(suite&1 && j == 1)][0]&(1<<6))>>6;
	    for(int x = 0 ; x < sizeof *C ; x++) {
	      int a = C[i-1+(suite&1 && j == 1)][x];
	      a<<=1;
	      a&=127;
        a+=((C[i-1+(suite&1 && j == 1)][x+1]&(1<<6))>>6);
	      C[i][x] = a;
	    }
	    C[i][(sizeof C[0])-1] -= C[i][(sizeof C[0])-1]%2;
	    C[i][(sizeof C[0])-1] ^= tmp;
	    
    }
  }
  for(int i = 1, suite = 16254 ; i < 16 ; i++, suite>>=1) {
    for(int j = (suite&1)+1; j > 0 ; j--) {
	    int tmp = (D[i-1+(suite&1 && j == 1)][0]&(1<<6))>>6;
	    for(int x = 0 ; x < sizeof *D ; x++) {
	      int a = D[i-1+(suite&1 && j == 1)][x];
	      a<<=1;
	      a&=127;
        a+=((D[i-1+(suite&1 && j == 1)][x+1]&(1<<6))>>6);
	      D[i][x] = a;
	    }
	    D[i][(sizeof D[0])-1] -= D[i][(sizeof D[0])-1]%2;
	    D[i][(sizeof D[0])-1] ^= tmp;
    }
  }
  for(int k = 0 ; k < 16 ; k++ )
    for(int i = 0 ; i < 8 ; i++) 
      for(int j = 0 ; j < 6 ; j++) {
        int a = CP2[i][j];
        subkeys[k][i*6+j] = 0;
        printf("%d-%d\n", i*6+j, k);
        subkeys[k][i*6+j] = !!(((a>28 ? (a-=28,D) : C)[k][(a-1)/7] ) & (1<<6-(a-1)%7));
      }
  for(int i = 0 ; i < 16 ; i++) {
    for(int j = 0 ; j < 48 ; j++)
      printf("%.1d", subkeys[i][j]);
    puts("");
  }
}
void initSubKeys(const unsigned char keyInit[]) {
	unsigned char keyPerm[56] = {0};
	for(int i = 0 ; i < 8; i++)
	  for( int j = 0 ; j < 7 ; ++j)
	    keyPerm[i*7+j] = nbit(CP1[i][j]-1, keyInit);
	
	unsigned char C[16][28] = {0};
	unsigned char D[16][28] = {0};
  
  { // C
	  for(int i = 0 ; i < 28 ; i++)
	    C[0][i] = keyPerm[i],
	    D[0][i] = keyPerm[i+28];
	 
    int a = C[0][0], d = D[0][0];
    C[0][0] = C[0][1];
    C[0][1] = C[0][2];
    C[0][2] = C[0][3];
    C[0][3] = C[0][4];
    C[0][4] = C[0][5];
    C[0][5] = C[0][6];
    C[0][6] = C[0][7];
    C[0][7] = C[0][8];
    C[0][8] = C[0][9];
    C[0][9] = C[0][10];
    C[0][10] = C[0][11];
    C[0][11] = C[0][12];
    C[0][12] = C[0][13];
    C[0][13] = C[0][14];
    C[0][14] = C[0][15];
    C[0][15] = C[0][16];
    C[0][16] = C[0][17];
    C[0][17] = C[0][18];
    C[0][18] = C[0][19];
    C[0][19] = C[0][20];
    C[0][20] = C[0][21];
    C[0][21] = C[0][22];
    C[0][22] = C[0][23];
    C[0][23] = C[0][24];
    C[0][24] = C[0][25];
    C[0][25] = C[0][26];
    C[0][26] = C[0][27];
    C[0][27] = a;
    
    D[0][0] = D[0][1];
    D[0][1] = D[0][2];
    D[0][2] = D[0][3];
    D[0][3] = D[0][4];
    D[0][4] = D[0][5];
    D[0][5] = D[0][6];
    D[0][6] = D[0][7];
    D[0][7] = D[0][8];
    D[0][8] = D[0][9];
    D[0][9] = D[0][10];
    D[0][10] = D[0][11];
    D[0][11] = D[0][12];
    D[0][12] = D[0][13];
    D[0][13] = D[0][14];
    D[0][14] = D[0][15];
    D[0][15] = D[0][16];
    D[0][16] = D[0][17];
    D[0][17] = D[0][18];
    D[0][18] = D[0][19];
    D[0][19] = D[0][20];
    D[0][20] = D[0][21];
    D[0][21] = D[0][22];
    D[0][22] = D[0][23];
    D[0][23] = D[0][24];
    D[0][24] = D[0][25];
    D[0][25] = D[0][26];
    D[0][26] = D[0][27];
    D[0][27] = d;
  }
  for(int i = 1, suite = 32508>>1 ; i < 16 ; i++, suite>>=1) {
    int b = -1,a, d;
    Go_tour:
    a = C[i+b][0];
    d = D[i+b][0];
    C[i][0] = C[i+b][1];
    C[i][1] = C[i+b][2];
    C[i][2] = C[i+b][3];
    C[i][3] = C[i+b][4];
    C[i][4] = C[i+b][5];
    C[i][5] = C[i+b][6];
    C[i][6] = C[i+b][7];
    C[i][7] = C[i+b][8];
    C[i][8] = C[i+b][9];
    C[i][9] = C[i+b][10];
    C[i][10] = C[i+b][11];
    C[i][11] = C[i+b][12];
    C[i][12] = C[i+b][13];
    C[i][13] = C[i+b][14];
    C[i][14] = C[i+b][15];
    C[i][15] = C[i+b][16];
    C[i][16] = C[i+b][17];
    C[i][17] = C[i+b][18];
    C[i][18] = C[i+b][19];
    C[i][19] = C[i+b][20];
    C[i][20] = C[i+b][21];
    C[i][21] = C[i+b][22];
    C[i][22] = C[i+b][23];
    C[i][23] = C[i+b][24];
    C[i][24] = C[i+b][25];
    C[i][25] = C[i+b][26];
    C[i][26] = C[i+b][27];
    C[i][27] = a;
    
    D[i][0] = D[i+b][1];
    D[i][1] = D[i+b][2];
    D[i][2] = D[i+b][3];
    D[i][3] = D[i+b][4];
    D[i][4] = D[i+b][5];
    D[i][5] = D[i+b][6];
    D[i][6] = D[i+b][7];
    D[i][7] = D[i+b][8];
    D[i][8] = D[i+b][9];
    D[i][9] = D[i+b][10];
    D[i][10] = D[i+b][11];
    D[i][11] = D[i+b][12];
    D[i][12] = D[i+b][13];
    D[i][13] = D[i+b][14];
    D[i][14] = D[i+b][15];
    D[i][15] = D[i+b][16];
    D[i][16] = D[i+b][17];
    D[i][17] = D[i+b][18];
    D[i][18] = D[i+b][19];
    D[i][19] = D[i+b][20];
    D[i][20] = D[i+b][21];
    D[i][21] = D[i+b][22];
    D[i][22] = D[i+b][23];
    D[i][23] = D[i+b][24];
    D[i][24] = D[i+b][25];
    D[i][25] = D[i+b][26];
    D[i][26] = D[i+b][27];
    D[i][27] = d;
    if( suite & 1 ) {
      b = 0;
      suite^=1;
      goto Go_tour;
    }
  }
  for(int k = 0 ; k < 16 ; k++ )
    for(int i = 0 ; i < 8 ; i++)
      for(int j = 0 ; j < 6 ; j++) {
        int a = CP2[i][j];
        subkeys[k][i*6+j] = 0;
        if( a > 28 ) 
          subkeys[k][i*6+j] = D[k][a-29];
        else 
          subkeys[k][i*6+j] = C[k][a-1];
      }
}
void DES_64_enc( unsigned char src[], unsigned char* key, unsigned char* out) {
  block message = { 0 }, PI = {0};
	initSubKeys(key);
  for(int i = 0 ; i < 8 ; i++) 
    message.D[i] = src[i];
	for(int i=0;i<8*8;++i)  // On effectue les permutations initiales
		setbit(i, &PI, nbit(((57 + (i<8*4) + 2 * (i/8)) - (8* (i%8 + !(i<8*4))))-1, &message));
		
	char matrice[48] = {0};
	for( int ite =  0 ; ite < 16 ; ite++) {
	  for(int i = 0;i < 6*8;i++)
	    matrice[i] = nbit( (((7+i/6)%8+1)*4 - 32* !(i/6 || !i) + i%6 - 32* !(i-47))-1, PI.d.D);
	    
	  for(int i = 0;i < 6*8;i++)
		  matrice[i] ^= subkeys[ite][i];

		unsigned char tmp[4] = {0};
		unsigned char tmp2[4] = {0};
		for(int i =  0; i < 8 ; i++) {
		  int L = 0, C = 0;
		  setbit(7-1,&L,matrice[6*i]);
		  setbit(7-0,&L,matrice[6*i+5]);
		  
		  setbit(7-3,&C,matrice[6*i+1]);
		  setbit(7-2,&C,matrice[6*i+2]);
		  setbit(7-1,&C,matrice[6*i+3]);
		  setbit(7-0,&C,matrice[6*i+4]);
		  
		  tmp[i/2] += tabS[i][L][C] << (((i+1)%2)*4);
		}
    for(int i =0;i<8;++i)
	    for(int j=0;j<4;++j)
		    setbit(i*4+j, &tmp2, nbit(pPerm[i][j]-1, &tmp));
	  
	  for(int i = 0 ; i < 4 ; i++ ) 
		  PI.d.G[i] ^= tmp2[i];
		  
		for(int i =  0 ; i < 4 ; i++ ) {
		  unsigned char tmp = PI.d.D[i];
		  PI.d.D[i] = PI.d.G[i];
		  PI.d.G[i] = tmp;
		} 
	}
  for(int i =  0 ; i < 4 ; i++ ) {
	  unsigned char tmp = PI.d.D[i];
		PI.d.D[i] = PI.d.G[i];
		PI.d.G[i] = tmp;
  }
	block MChiffred = {0};
	for(int i = 0;i< 8;i++) 
	  for( int j = 0 ; j < 8 ; j++)
		  setbit(i*8+j,&MChiffred.D,  nbit(fPerm[i][j]-1,PI.D));
  for(int i = 0; i < 8 ; i++)
    out[i] = MChiffred.D[i];
} 
void DES_64_dec( unsigned char* src, unsigned char* key, unsigned char* out) {
  
  block PO = {0}, in = {0};
  initSubKeys(key);
  for(int i = 0 ; i < 8 ; i++ ) 
    in.D[i] = src[i];
  for(int i = 0;i<64;i++)
    setbit( i,&PO.D, nbit(((57 + (i<8*4) + 2 * (i/8)) - (8* (i%8 + !(i<8*4))))-1, in.D));
  for(int i =  0 ; i < 4 ; i++ ) {
    unsigned char tmp = PO.d.D[i];
    PO.d.D[i] = PO.d.G[i];
    PO.d.G[i] = tmp;
  }
  char matrice[48] = {0};
  for( int ite =  15 ; ite >=0 ; ite--) {
    for(int i = 0;i < 6*8;i++)
      matrice[i] = nbit( (((7+i/6)%8+1)*4 - 32* !(i/6 || !i) + i%6 - 32* !(i-47))-1, PO.d.G);
    
    for(int i = 0;i < 6*8;i++)
      matrice[i] ^= subkeys[ite][i];

    unsigned char tmp[4] = {0};
		unsigned char tmp2[4] = {0};
		
    for(int i =  0; i < 8 ; i++) {
      int L = 0, C = 0;
      setbit(7-1,&L,matrice[6*i]);
      setbit(7-0,&L,matrice[6*i+5]);
		  
      setbit(7-3,&C,matrice[6*i+1]);
      setbit(7-2,&C,matrice[6*i+2]);
      setbit(7-1,&C,matrice[6*i+3]);
      setbit(7-0,&C,matrice[6*i+4]);
		  
      tmp[i/2] += tabS[i][L][C] << (((i+1)%2)*4);
    }
    for(int i =0;i<8;++i)
      for(int j=0;j<4;++j)
        setbit(i*4+j, &tmp2, nbit(pPerm[i][j]-1, &tmp));
    
    for(int i = 0 ; i < 4 ; i++ ) 
      PO.d.D[i] ^= tmp2[i];
		  
    
    for(int i =  0 ; i < 4 ; i++ ) {
      unsigned char tmp = PO.d.D[i];
      PO.d.D[i] = PO.d.G[i];
      PO.d.G[i] = tmp;
    }
  }
  block DEChiffred = {0};
  for(int i = 0;i< 8;i++) 
    for( int j = 0 ; j < 8 ; j++)
      setbit(i*8+j,&DEChiffred.D,  nbit(fPerm[i][j]-1,PO.D));
  for(int i = 0; i < 8 ; i++)
    out[i] = DEChiffred.D[i];
}


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



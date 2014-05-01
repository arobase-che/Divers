#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include <math.h>

#define X_S		500
#define Y_S		500

#define _mask( o ) ((int)o & 255)
#define _tmp(h, o ) (h-_mask(o))
#define _interpolation( o ) ( - 2 * o * o * o +  3 * o * o)
#define unit 1.0f / sqrt(2.)
#define _pond( h, o) ( perm[ (_mask(h) + perm[_mask(o)]) % 256] %8 )

void swap(int* a, int* b) {
  int c = *a;
  *a = *b;
  *b = c;
}
void shuffle( int* perm ) {
  for(int i = 0 ; i < 256 ; i++ )
    swap(perm+i, perm+(rand()%256));
}
float perlinNose(float x, float y, float res)
{
    float tempX,tempY;
    int x0,y0,ii,jj,gi0,gi1,gi2,gi3;
    float tmp,s,t,u,v,Cx,Cy,Li1,Li2;
    float vec[8][2] = {{unit,unit},{-unit,unit},{unit,-unit},{-unit,-unit},{1,0},{-1,0},{0,1},{0,-1}};

    static unsigned int perm[256] = { -1 };
    if( perm[0] == -1 ) {
      for(int i = 0 ; i < 256 ; i++) 
        perm[i] = i;
      shuffle(perm);
    }
    x /= res;
    y /= res;

    s = vec[_pond(x, y)][0]*_tmp(x, x)       + vec[_pond(x, y)][1]*_tmp(y, y);
    t = vec[_pond(x+1, y)][0]*_tmp(x, x+1)   + vec[_pond(x+1, y)][1]*_tmp(y, y);
    u = vec[_pond(x, y+1)][0]*_tmp(x, x)     + vec[_pond(x, y+1)][1]*_tmp(y, y+1);
    v = vec[_pond(x+1, y+1)][0]*_tmp(x, x+1) + vec[_pond(x+1, y+1)][1]*_tmp(y, y+1);


    //Lissage
    Li1 = s + _interpolation( _tmp(x, x))*(t-s);
    Li2 = u + _interpolation( _tmp(x, x))*(v-u);

    return Li1 + _interpolation( _tmp(y, y))*(Li2-Li1);
}
void putPixel(SDL_Surface * surface, Uint16 x, Uint16 y, Uint32 color)
{
  Uint8 * p = ((Uint8 *)surface->pixels) + y * surface->pitch + x * 4;
  *(Uint32 *)p = color;
}
void ERNO(int error, char* t)
{
	switch(error)
	{
		case 1:
			printf("Init error");break;
		case 2:
			printf("Alloc error");
	}
	if(t)
		putchar(':'),puts(t);
	exit(error);
}
int main(void)
{
	SDL_Surface* screen = NULL;
	srand(time(NULL));
	if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
		ERNO(1,"SDL_Init");
	atexit(SDL_Quit);
  
	if(! (screen=SDL_SetVideoMode(X_S, Y_S, 32, SDL_SWSURFACE | SDL_DOUBLEBUF)))
 		ERNO(1,"VideoMode");
 
	SDL_Event event;
	
	{
		int x, y;
		sta:
		for(x=0;x< X_S;x++)
			for(y=0;y<Y_S;y++)
			{
			  int u = ((int)((perlinNose(x, y, 100.)+1)/2.*255.));
        putPixel(screen, x, y, SDL_MapRGB(screen->format, u, u, u));
		  }
	 	SDL_Flip(screen);
		while(SDL_WaitEvent(&event))if(event.type == SDL_QUIT)return 0;else goto sta;
	}
  return 0;
}

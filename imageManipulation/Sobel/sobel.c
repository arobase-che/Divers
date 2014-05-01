#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

// Compile avec : gcc AlgoSobel.c -lSDL -lSDL_image 


#define to8(x) (Uint8)(x/total)
SDL_Surface *screen = NULL;

char name[100];
Uint32 getPixel(SDL_Surface * surface, int x, int y)
{
  int bpp = surface->format->BytesPerPixel;
  Uint8 *p = (Uint8 *) surface->pixels + y * surface->pitch + x * bpp;

  switch (bpp) {
  case 1:
    return *p;
  case 2:
    return *(Uint16 *) p;
  case 3:
    if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
      return p[0] << 16 | p[1] << 8 | p[2];
    else
      return p[0] | p[1] << 8 | p[2] << 16;
  case 4:
    return *(Uint32 *) p;

  default:
    return 0;
  }
}
void putPixel(SDL_Surface * surface, Uint16 x, Uint16 y, Uint32 color)
{
  Uint8 bpp = surface->format->BytesPerPixel;
  Uint8 *p = ((Uint8 *) surface->pixels) + y * surface->pitch + x * bpp;
  switch (bpp) {
  case 1:
    *p = (Uint8) color;
    break;
  case 2:
    *(Uint16 *) p = (Uint16) color;
    break;
  case 3:
    if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
      *(Uint16 *) p = ((color >> 8) & 0xff00) | ((color >> 8) & 0xff);
      *(p + 2) = color & 0xff;
    } else {
      *(Uint16 *) p = color & 0xffff;
      *(p + 2) = ((color >> 16) & 0xff);
    }
    break;
  case 4:
    *(Uint32 *) p = color;
    break;
  }
}
void ERNO(int error, char *t)
{
  switch (error) {
  case 1:
    printf("Init error");
    break;
  case 2:
    printf("Alloc error");
  }
  if (t)
    putchar(':'), puts(t);
  puts("");
  exit(error);
}
void niveauGris(SDL_Surface * img)
{
  uint32_t pix, R, B, G, A, tmp;
  int i, j;
  
  for(i = 0; i < img->w ;++i)
    for(j = 0; j < img->h ;++j)
    {
      pix = getPixel(img, i, j);
      
      //Red
      tmp = pix & img->format->Rmask;
      tmp = tmp >> img->format->Rshift;
      tmp = tmp << img->format->Rloss;
      R   = tmp;

      //Green 
      tmp = pix & img->format->Gmask;
      tmp = tmp >> img->format->Gshift;
      tmp = tmp << img->format->Gloss;
      G   = tmp;

      //Blue
      tmp = pix & img->format->Bmask;
      tmp = tmp >> img->format->Bshift;
      tmp = tmp << img->format->Bloss;
      B   = tmp;

      //Alpha 
      tmp = pix & img->format->Amask;
      tmp = tmp >> img->format->Ashift;
      tmp = tmp << img->format->Aloss;
      A   = tmp;
      
      pix = (R+B+G)/3 + ((R+B+G)%3)/2;
      tmp = (pix & img->format->Rmask) << img->format->Rshift & 
            (pix & img->format->Bmask) << img->format->Bshift & 
            (pix & img->format->Gmask) << img->format->Gshift & 
            (A   & img->format->Amask) << img->format->Ashift ; 
      
      
      putPixel(img, i, j, SDL_MapRGBA(img->format, pix, pix, pix, A));
      
    }
  unsigned int x = 0, y = 0;
  (img->w > img->h) ? (y = img->h) : (x = img->w);
  SDL_Rect pos = { x, y };
  SDL_BlitSurface(img, NULL, screen, &pos);
}
void contourSobel(SDL_Surface * img)
{
  SDL_Surface *img2 = IMG_Load(name);
  uint64_t pix, Gx, Gy, G, R, B, g, A, tmp;
  int i, j;
  
  //flouRapid(img);
  for(i = 1; i < (img->w-1) ;++i)
    for(j = 1, Gx = Gy = 0; j < (img->h-1) ;++j)
    {
      for(int I = -1; I <= 1 ; ++I)
        for(int J = -1; J <= 1 ; ++J)
        {
          pix = getPixel(img, i+I, j+J);
      //Red
          tmp = pix & img->format->Rmask;
          tmp = tmp >> img->format->Rshift;
          tmp = tmp << img->format->Rloss;
          R   = tmp;

      //Green 
          tmp = pix & img->format->Gmask;
          tmp = tmp >> img->format->Gshift;
          tmp = tmp << img->format->Gloss;
          g   = tmp;

      //Blue
          tmp = pix & img->format->Bmask;
          tmp = tmp >> img->format->Bshift;
          tmp = tmp << img->format->Bloss;
          B   = tmp;
      
          pix = (R+B+g)/3 + ((R+B+g)%3)/2;
          
          Gy += pix * (-I) * (int[]){ 1,2,1 }[J+1];
          Gx += pix * (-J) * (int[]){ 1,2,1}[I+1];
        }
        //Alpha 
        tmp = getPixel(img, i, j) & img->format->Amask;
        tmp = tmp >> img->format->Ashift;
        tmp = tmp << img->format->Aloss;
        A   = tmp;
        Gx = abs(Gx)/2;
        Gy = abs(Gy)/2;
        G = Gx+Gy;//(uint32_t)sqrt(Gx*Gx+Gy*Gy);
        G /=2;
        
        putPixel(img2, i, j, SDL_MapRGBA(img->format, G, G, G, 255));
    }
  unsigned int x = 0, y = 0;
  (img->w > img->h) ? (y = img->h) : (x = img->w);
  SDL_Rect pos = { x, y };
  SDL_BlitSurface(img2, NULL, screen, &pos);
}
int main(void)
{
  int a = 0;
  SDL_Surface *img = NULL, *tmp = NULL;
  SDL_Event event;

  puts("Appliquer un filtre de Sobel(0) ou une dessaturisation(!0) ?");
  scanf("%d", &a);
  puts("Sélectionner une image :");
  scanf("%s", name);
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    ERNO(1, "SDL_Init");
  atexit(SDL_Quit);

  if (img = IMG_Load(name))
    puts("Ok");
  else
    ERNO(2, name);

  if (!(screen = SDL_SetVideoMode(((img->w > img->h) ? img->w : img->w * 2), ((img->w > img->h) ? img->h * 2 : img->h), 16, SDL_SWSURFACE | SDL_DOUBLEBUF)))
    ERNO(1, "VideoMode");

  SDL_BlitSurface(img, NULL, screen, NULL);

  while (1) {
    a ? niveauGris(img) : contourSobel(img);
    SDL_Flip(screen);
    while (SDL_WaitEvent(&event))
      if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_ESCAPE))
	return 0;
  }

  return 0;
}


#ifndef BASE_H_ENC
#define BASE_H_ENC

void to_URI(char *dst, const char *src) {

  for(int i = 0, j = 0 ; src[i] ; ++i)
    switch(src[i]) {
      case ' ':
        dst[j++] = '%';
        dst[j++] = '2';
        dst[j++] = '0';
      break;
      case '\t'://
        dst[j++] = '%';
        dst[j++] = '0';
        dst[j++] = '9';
      break;
      case '<':
        dst[j++] = '%';
        dst[j++] = '3';
        dst[j++] = 'C';
      break;
      case '>':
        dst[j++] = '%';
        dst[j++] = '3';
        dst[j++] = 'E';
      break;
      case '#':
        dst[j++] = '%';
        dst[j++] = '2';
        dst[j++] = '3';
      break;
      case '%':
        dst[j++] = '%';
        dst[j++] = '2';
        dst[j++] = '5';
      break;
      case '{':
        dst[j++] = '%';
        dst[j++] = '7';
        dst[j++] = 'B';
      break;
      case '}':
        dst[j++] = '%';
        dst[j++] = '7';
        dst[j++] = 'D';
      break;
      case '|':
        dst[j++] = '%';
        dst[j++] = '7';
        dst[j++] = 'C';
      break;
      case '\\':
        dst[j++] = '%';
        dst[j++] = '5';
        dst[j++] = 'C';
      break;
      case '^':
        dst[j++] = '%';
        dst[j++] = '5';
        dst[j++] = 'E';
      break;
      case '~':
        dst[j++] = '%';
        dst[j++] = '7';
        dst[j++] = 'E';
      break;
      case '[':
        dst[j++] = '%';
        dst[j++] = '5';
        dst[j++] = 'B';
      break;
      case ']':
        dst[j++] = '%';
        dst[j++] = '5';
        dst[j++] = 'D';
      break;
      case '`':
        dst[j++] = '%';
        dst[j++] = '6';
        dst[j++] = '0';
      break;
      default:
        dst[j++] = src[i];
    }
}
void from_URI(char *dst, const char *src) {
  int i = 0,j = 0;
  for(i = 0, j = 0; src[i] ; ++i)
    if( src[i] == '%' ) {
      i++;
      dst[j++] = (((src[i] >= '0' && src[i] <= '9') ? src[i]-'0' : src[i]-'A'+10)*16+((src[i+1] >= '0' && src[i+1] <= '9') ? src[i+1]-'0' : src[i+1]-'A'+10));
      i++;
    } else
      dst[j++] = src[i];
  dst[j] = 0;
}


void HTO (char *dst, const char *src) {
  char fin = 0;

  dst[0] = ( HALPHA[src[0] >> 2]);
  dst[1] = ( HALPHA[((src[0] & 3) << 4) + (src[1] >> 4 & 15)]);
  dst[2] = (src[1] ? HALPHA [((src[1] & 15) << 2) + (src[2] >> 6)] : (fin = HALPHA[64]));
  dst[3] = (src[1] && src[2] ? HALPHA[src[2] & 63] : (fin = HALPHA[64] ));

  if (!fin && src[3])
    HTO(dst + 4, src + 3);
  else
    dst[4] = 0;
}
void HFROM (char *dst, const char *src) {
  char fin = 1;

  dst[0] = ((HDEC[src[0]] << 2) + (HDEC[src[1]] >> 4));
  dst[1] = (src[2] != HALPHA[64]) ? ((HDEC[src[1]] << 4) + (HDEC[src[2]] >> 2)) : (fin = 0);
  dst[2] = (src[3] != HALPHA[64]) ? ((HDEC[src[2]] << 6) + HDEC[src[3]]) : (fin = 0);

  if (fin && src[4])
    HFROM(dst + 3, src + 4);
  else
    dst[3] = 0;
}

#include<stdlib.h>
void HURIFROM (char *dst, const char *src ) {
  HFROM(dst, src);
  from_URI(dst, dst);
}
void HURITO (char *dst, const char *src ) {
  unsigned size = 0, i = 0;
  while( src[i] ) {
    for(int j = 0 ; " \t<>#%[}|^~[]`"[j] ; ++j)
      if( src[i] == " \t<>#%[}|^~[]`"[j]) {size+=2;break;}
    ++size,i++;
  }
  char* tmp = malloc( size + 1);
  to_URI(tmp, src);
  HTO(dst, tmp);
  free(tmp);
}

#endif



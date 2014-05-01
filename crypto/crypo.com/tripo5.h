

#ifndef TRIPO5_ENC
#define TRIPO5_ENC


void to_tripo5(char *dst, const char *src);
void from_tripo5(char *dst, const char *src);
void to_URI_tripo5(char *dst, const char *src);
void from_URI_tripo5(char *dst, const char *src);
void to_FURI_tripo5(char *dst, char* tmp, const char *src);
void from_FURI_tripo5(char *dst, char* tmp, const char *src);

#endif



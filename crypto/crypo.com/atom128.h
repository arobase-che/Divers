

#ifndef ATOM128_ENC
#define ATOM128_ENC


void to_atom128(char *dst, const char *src);
void from_atom128(char *dst, const char *src);
void to_URI_atom128(char *dst, const char *src);
void from_URI_atom128(char *dst, const char *src);
void to_FURI_atom128(char *dst, char* tmp, const char *src);
void from_FURI_atom128(char *dst, char* tmp, const char *src);

#endif



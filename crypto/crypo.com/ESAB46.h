

#ifndef ESAB46_ENC
#define ESAB46_ENC


void to_ESAB46(char *dst, const char *src);
void from_ESAB46(char *dst, const char *src);
void to_URI_ESAB46(char *dst, const char *src);
void from_URI_ESAB46(char *dst, const char *src);
void to_FURI_ESAB46(char *dst, char* tmp, const char *src);
void from_FURI_ESAB46(char *dst, char* tmp, const char *src);

#endif



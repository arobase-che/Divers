

#ifndef FERON74_ENC
#define FERON74_ENC


void to_feron74(char *dst, const char *src);
void from_feron74(char *dst, const char *src);
void to_URI_feron74(char *dst, const char *src);
void from_URI_feron74(char *dst, const char *src);
void to_FURI_feron74(char *dst, char* tmp, const char *src);
void from_FURI_feron74(char *dst, char* tmp, const char *src);

#endif



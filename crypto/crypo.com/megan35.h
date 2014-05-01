

#ifndef MEGAN35_ENC
#define MEGAN35_ENC


void to_megan35(char *dst, const char *src);
void from_megan35(char *dst, const char *src);
void to_URI_megan35(char *dst, const char *src);
void from_URI_megan35(char *dst, const char *src);
void to_FURI_megan35(char *dst, char* tmp, const char *src);
void from_FURI_megan35(char *dst, char* tmp, const char *src);

#endif



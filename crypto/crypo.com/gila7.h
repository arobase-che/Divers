

#ifndef GILA7_ENC
#define GILA7_ENC


void to_gila7(char *dst, const char *src);
void from_gila7(char *dst, const char *src);
void to_URI_gila7(char *dst, const char *src);
void from_URI_gila7(char *dst, const char *src);
void to_FURI_gila7(char *dst, char* tmp, const char *src);
void from_FURI_gila7(char *dst, char* tmp, const char *src);

#endif



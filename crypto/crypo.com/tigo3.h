

#ifndef TIGO3_ENC
#define TIGO3_ENC


void to_tigo3(char *dst, const char *src);
void from_tigo3(char *dst, const char *src);
void to_URI_tigo3(char *dst, const char *src);
void from_URI_tigo3(char *dst, const char *src);
void to_FURI_tigo3(char *dst, char* tmp, const char *src);
void from_FURI_tigo3(char *dst, char* tmp, const char *src);

#endif



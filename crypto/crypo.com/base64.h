

#ifndef BASE64_ENC
#define BASE64_ENC


void to_base64(char *dst, const char *src);
void from_base64(char *dst, const char *src);
void to_URI_base64(char *dst, const char *src);
void from_URI_base64(char *dst, const char *src);

#endif



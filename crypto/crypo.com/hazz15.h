

#ifndef HAZZ15_ENC
#define HAZZ15_ENC


void to_hazz15(char *dst, const char *src);
void from_hazz15(char *dst, const char *src);
void to_URI_hazz15(char *dst, const char *src);
void from_URI_hazz15(char *dst, const char *src);
void to_FURI_hazz15(char *dst, char* tmp, const char *src);
void from_FURI_hazz15(char *dst, char* tmp, const char *src);

#endif



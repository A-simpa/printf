#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>

int _printf(const char *format, ...);
int print_s(char *s);
int print_S(char *s);
int print_c(char ch);
int pr_flag(const char *s);
int text_print(va_list, const char *s);
int print_in(long int n, int flag);
int print_uin(unsigned int u, int flag);
int bin(unsigned int dec, int flag);
int heXx(unsigned int dec, int flag, int type);
int oct(unsigned int dec, int flag);
int uuint(unsigned int u, int flag);
#endif

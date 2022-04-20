#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>

int _printf(const char *format, ...);
int print_s(char *s);
int print_c(char ch);
int pr_flag(const char *s);
int text_print(va_list, const char *s);


#endif

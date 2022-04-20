#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
* _printf - produces output according to format
* @format: first parameter of type char
* Return: Always 0
*/

int _printf(const char *format, ...)
{
	va_list ptr;
	int num = 0;

	if (!format)
		return (-1);

	else
	{
		va_start(ptr, format);

		num += text_print(ptr, format);
	}
	va_end(ptr);
	return (num);
}

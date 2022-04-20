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
	int num = 0, i = 0;

	if (!format)
		return (-1);

	else
	{
		va_start(ptr, format);
		for (; *format != '\0'; format++)
		{
			if (*format == '%')
			{
				i++;
				continue;
			}
			else if (i != 0 &&  *(format - 1) == '%')
			{
				if (*format == 'c')
					num += print_c(va_arg(ptr, int));
				else if (*format == 's')
					num += print_s(va_arg(ptr, char *));
			}
			else
			{
				num += write(1, format, 1);
			}
			i++;
		}
	}
	va_end(ptr);
	return (num);
}

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
	int i = 0;
	char *str;
	char dan;
	int j = 0;
	char *muj;
	char *z, *y;

	if (format)
	{
		va_start(ptr, format);
		while (format[i] != '\0')
		{
			if (format[i] == '%' && format[i + 1] == 'c')
			{
				dan = va_arg(ptr, int);
				str = &dan;
				num += write(1, str, 1);
			}
			else if (format[i] && format[i + 1] == 's')
			{
				muj = va_arg(ptr, char *);
				if (muj)
				{
					while (muj[j] != '\0')
					{
						z = &muj[j];
						num += write(1, z, 1);
						j++;
					}
				}
				else
				{
					y = "(null)";
					num += write(1, y, 6);
				}
			}
			i++;
		}
	}
	va_end(ptr);
	return (num);
}

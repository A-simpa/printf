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#include "main.h"
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
	int num = 0, j = 0, i = 0;
	char dan, *muj, *z, *y, *str;

	if (!format)
		return (-1);

	else
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
					for (; muj[j] != '\0'; j++)
					{
						z = &muj[j];
						num += write(1, z, 1);
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

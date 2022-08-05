#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * print_S - print a string with non print non printable
 * @s: the string to print
 *
 * Return: return number of characters printed
 */

int print_S(char *s)
{
	int i = 0, num = 0;
	char *r;

	if (s)
	{
		while (s[i]  != '\0')
		{
			if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
			{
				num += write(1, "\\", 1);
				num += write(1, "x", 1);
				if (s[i] <= 15)
					num += write(1, "0", 1);
				num += heXx(s[i], 0, 0);
			}
			else
				num += print_c(s[i]);
			i++;
		}
	}
	else
	{
		r = "(null)";
		num += write(1, r, 6);
	}
	return (num);
}

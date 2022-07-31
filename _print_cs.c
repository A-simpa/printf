#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
*print_s - prints a string
*@s: a pointer to the string
*
*Return: returns the number of character printed
*/

int print_s(char *s)
{

int i = 0, num = 0;
char *e, *r;

if (s)
{
	while (s[i] != '\0')
	{
		e = &s[i];
		num += write(1, e, 1);
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

/**
* print_c - function for character specifier
* @ch: of type char
* Return: Always 0
*/

int print_c(char ch)
{
	int num = 0;
	char *r;

	r = &ch;
	num += write(1, r, 1);
	return (num);
}


/**
 * pr_flag - return a flag to a condition
 *
 * @s: the pointer to the string
 * Return: returns an int
 */


int pr_flag(const char *s)
{
	if (*s == '%' && *(s + 1) == '%')
		return (2);
	else if (*s == '%' && (*(s + 1) == 'c' || *(s + 1) == 's'))
		return (1);
	else if (*s == '%' && (*(s + 1) == 'd' || *(s + 1) == 'u'))
		return (4);
	else if (*s == '%' && (*(s + 1)) == 'i')
		return (3);
	else if (*s == '%' && (*(s + 1)) == 'b')
		return (5);
	else if (*s == '%' && (*(s + 1)) == 'o')
		return (6);
	else if (*s == '%' && (*(s + 1)) == 'X')
		return (7);
	else if (*s == '%' && (*(s + 1)) == 'x')
		return (8);
	else if (*s == '%' && *(s + 1) == '\0')
		return (-1);
	return (0);
}


/**
 * text_print - implement the actual printing
 * @s: character to check
 * @ptr: the variadic list to print option
 *
 * Return: int
 */


int text_print(va_list ptr, const char *s)
{
	int flag, num = 0;
	char *p = "%";

	for (; *s != '\0'; s++)
	{
		flag = pr_flag(s);
		if (flag == 2)
			num += write(1, p, 1), s++;
		else if (flag == 1)
		{
			if (*(s + 1) == 'c')
				num += print_c(va_arg(ptr, int));
			else
				num += print_s(va_arg(ptr, char *));
			s++;
		}
		else if (flag == 4)
			num += print_in(va_arg(ptr, int), 0), s++;
		else if (flag == 3)
			num += print_in(va_arg(ptr, int), 0), s++;
		else if (flag == 5)
			num += bin(va_arg(ptr, int), 0), s++;
		else if (flag == 6)
			num += oct(va_arg(ptr, int), 0), s++;
		else if (flag == 7)
			num += heXx(va_arg(ptr, int), 0, 0), s++;
		else if (flag == 8)
			num += heXx(va_arg(ptr, int), 0, 1), s++;
		else if (flag == -1)
		{
			num += -1;
			continue;
		}
		else
			num += write(1, s, 1);
	}
	return (num);
}

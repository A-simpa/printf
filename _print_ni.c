#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 *print_in - prints integer
 *@n: the integer to print
 *
 *Return: the number of character printed
 */

int print_in(int n)
{
	int *num, out, count = 0;
	char *sign = "-";

	if (n < 0)
	{
		n = n * -1;
		count += write(1, sign, 1);
	}
	if (n == 0)
		return (0);

	out = (n % 10) + '0';
	num  = &out;
	print_in((n / 10));
	count += write(1, num, 1);
	return (count);
}


/**
 *print_uin - prints unsigned int
 *@u: the unsigned int
 *
 *Return: the number of character printed
 */

int print_uin(unsigned int u)
{
	unsigned int ut, *num, count = 0;

	if (u == 0)
		return (0);


	ut = (u % 10) + '0';
	num  = &ut;
	print_uin((u / 10));
	count += write(1, num, 1);
	return (count);

}

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 *print_in - prints integer
 *@n: the integer to print
 *@flag: flags when a function have been called
 *
 *Return: the number of character printed
 */

int print_in(long int n, int flag)
{
	long int *num, out;
	int count = 0;
	char *sign = "-";

	if (n < 0)
	{
		flag += 1;
		n = n * -1;
		count += write(1, sign, 1);
	}
	if (n == 0)
	{
		if (flag == 0)
			count = write(1, "0", 1);
		return (count);
	}
	flag += 1;
	out = (n % 10) + '0';
	num  = &out;
	count += print_in((n / 10), flag);
	write(1, num, 1);
	return (count + 1);
}


/**
 *print_uin - prints unsigned int
 *@u: the unsigned int
 *@flag: signifies when count is to be intialized
 *Return: the number of character printed
 */

int print_uin(unsigned int u, int flag)
{
	unsigned int ut, *num, count = 0;

	if (u == 0)
	{
		if (flag == 0)
			count = write(1, "0", 1);
		return (count);
	}
	flag += 1;
	ut = (u % 10) + '0';
	num  = &ut;
	count += print_uin((u / 10), flag);
	write(1, num, 1);
	return (count + 1);

}

/**
 * bin - converts decimal numbers to binary
 * @flag: tells the number of time the function was called
 * @dec: the decimal to convert
 * Return: returns the number of byte printed
 */

int  bin(unsigned int dec, int flag)
{
	unsigned int r;
	int count = 0;

	if (dec == 0)
	{
		if (flag == 0)
		{
			count += write(1, "0", 1);
			return (count);
		}
		return (0);
	}
	flag = 1;
	r = (dec % 2) + '0';
	count += bin(dec / 2, flag);
	write(1, &r, 1);
	return (count + 1);
}

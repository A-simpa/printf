#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * oct - convert decimal number to octal
 * @flag: tells whether it is first time the func is called
 * @dec: the decimal to convert
 * Return: returns the number of byte printed
 */

int oct(unsigned int dec, int flag)
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
	r = (dec % 8) + '0';
	count += oct(dec / 8, flag);
	write(1, &r, 1);
	return (count + 1);
}

/**
 * heXx - convert decimal number to hexadecimal
 * @flag: tells whether it is first time the func is called
 * @dec: the decimal to convert
 * @type: the type hex
 * Return: returns the number of byte printed
 */

int heXx(unsigned int dec, int flag, int type)
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
	if (dec % 16 > 9)
		if (type == 0)
			r = (dec % 16) + '7';
		else
			r = (dec % 16) + 'W';
	else
		r = (dec % 16) + '0';
	count += heXx(dec / 16, flag, type);
	write(1, &r, 1);
	return (count + 1);
}

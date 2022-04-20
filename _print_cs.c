#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
*print_s - prints a string
*@s - a pointer to the string
*
*Return - returns the number of character printed
*/

int print_s(char *s)
{

int i = 0, num = 0;
char *e, *r;

if (s)
{
	while(s[i] != '\0')
	{
		e = &s[i];
		num += write(1, e, 1);
		i++;
	}
}
else
{
	r = "(null)";
	write(1, r, 6);
	num += 1;
}
return (num);
}

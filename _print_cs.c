#include "main.h"
#include <stdio.h>
#include <unistd.h>

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

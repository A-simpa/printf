#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main(void)
{
    _printf("%u\n", -1024);
    _printf("%b\n%X\n%x\n%o\n", 1024, 1035, 1035, 1024);
    return (_printf("%S\n", "Best\nSchool"));
}

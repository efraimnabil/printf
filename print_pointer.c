#include "main.h"

/**
 * print_pointer - function that prints a pointer address
 * @p: the pointer to print
 *
 * Return: the number of characters printed
 */
int print_pointer(void *p)
{
	char c[30];
	char sf[3];

	sf[0] = '%';
	sf[1] = 'p';
	sf[2] = '\0';
	sprintf(c, sf, p);
	return (write(1, c, strlen(c)));
}

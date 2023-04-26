#include "main.h"

/**
 * print_int - function that prints an integer
 * @n: the integer to print
 * @c: character representing the format specifier
 *
 * Return: the number of characters printed
 */

int print_int(long int n, char c)
{
	char str[30];
	char sf[3];

	sf[0] = '%';
	sf[1] = c;
	sf[2] = '\0';
	sprintf(str, sf, n);
	return (write(1, str, strlen(str)));
}

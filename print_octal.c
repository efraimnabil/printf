#include "main.h"

/**
 * print_octal - Function that prints an unsigned integer in octal.
 * @n: The unsigned integer to print.
 *
 * Return: The number of characters printed.
 */
int print_octal(unsigned int n)
{
    int len = 0;

    if (n / 8)
    {
        len += print_octal(n / 8);
    }
    len += write(1, &"01234567"[n % 8], 1);
    return (len);
}

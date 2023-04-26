#include "main.h"

/**
 * print_unsigned - function that prints an unsigned integer
 * @n: the unsigned integer to print
 *
 * Return: the number of characters printed
 */

int print_unsigned(unsigned int n)
{
    int len = 0;

    if (n / 10)
    {
        len += print_unsigned(n / 10);
    }
    len += write(1, &"0123456789"[n % 10], 1);
    return (len);
}

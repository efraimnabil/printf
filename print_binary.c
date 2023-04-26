#include "main.h"

/**
 * print_binary - function that prints an unsigned integer in binary
 * @n: the unsigned integer to print
 *
 * Return: the number of characters printed
 */

int print_binary(unsigned int n)
{
    int len = 0;

    if (n / 2)
    {
        len += print_binary(n / 2);
    }
    len += write(1, &"01"[n % 2], 1);
    return (len);
}

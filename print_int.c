#include "main.h"

/**
 * print_int - function that prints an integer
 * @n: the integer to print
 *
 * Return: the number of characters printed
 */

int print_int(int n)
{
    int len = 0;

    if (n < 0)
    {
        len += write(1, "-", 1);
        n = -n;
    }
    if (n / 10)
    {
        len += print_int(n / 10);
    }
    len += write(1, &"0123456789"[n % 10], 1);
    return (len);
}

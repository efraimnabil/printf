#include "main.h"

/**
 * print_hex - function that prints an unsigned integer in hexadecimal
 * @n: the unsigned integer to print
 * @cap: flag to indicate if the letters should be uppercase
 *
 * Return: the number of characters printed
 */

int print_hex(unsigned int n, int cap)
{
    int len = 0;

    if (n / 16)
    {
        len += print_hex(n / 16, cap);
    }

    if (cap == 0)
    {
        len += write(1, &"0123456789abcdef"[n % 16], 1);
    }
    else
    {
        len += write(1, &"0123456789ABCDEF"[n % 16], 1);
    }

    return (len);
}

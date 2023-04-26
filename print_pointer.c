#include "main.h"

/**
 * print_pointer - function that prints a pointer address
 * @p: the pointer to print
 *
 * Return: the number of characters printed
 */
int print_pointer(void *p)
{
    int len = 0;
    unsigned long int n = (unsigned long int)p;

    len += write(1, "0x", 2);
    len += print_hex(n, 0);
    return (len);
}

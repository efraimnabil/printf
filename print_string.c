#include "main.h"

/**
 * print_string - function that prints a string
 * @s: the string to print
 *
 * Return: the number of characters printed
 */
int print_string(char *s)
{
    int len = 0;

    while (*s)
    {
        len += write(1, s, 1);
        s++;
    }
    return (len);
}

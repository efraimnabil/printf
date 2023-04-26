#include "main.h"

/**
 * print_char - function that prints a character
 * @c: the character to print
 *
 * Return: the number of characters printed
 */
int print_char(char c)
{
    int len = 0;

    len += write(1, &c, 1);
    return (len);
}
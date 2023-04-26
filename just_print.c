#include "main.h"

/**
 * just_print - function that prints a character without formatting
 * @c: the character to print
 *
 * Return: the number of characters printed
 */

int just_print(char c)
{
    int len = 0;

    len += write(1, &c, 1);
    return (len);
}

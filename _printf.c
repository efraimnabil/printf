#include "main.h"

/**
 * _printf - prints a formatted string
 * @fmt: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *fmt, ...)
{
    va_list ap;
    int len = 0;

    va_start(ap, fmt);

    if(fmt == NULL){
        return (-1);
    }
    while (*fmt)
    {
        if (*fmt == '%')
        {
            len += handle_percent((char *)fmt, ap);
            fmt++;
        }
        else
        {
            len += just_print(*fmt);
        }
        fmt++;
    }
    va_end(ap);

    return (len);
}

#include "main.h"

/**
 * handle_percent - Handles the conversion specifiers for printf
 *
 * @fmt: Format specifier
 * @ap: List of arguments to parse
 *
 * Return: Number of characters printed
 */

int handle_percent(char *fmt, va_list ap)
{
    int len = 0;
    char *s;
    char c;
    int n;
    void *p;

    fmt++;
    switch (*fmt)
    {
    case 's':
        s = va_arg(ap, char *);
        if (s == NULL)
        {
            s = "(null)";
        }
        len += print_string(s);
        break;
    case 'c':
        c = va_arg(ap, int);
        len += print_char(c);
        break;
    case 'd':
        n = va_arg(ap, int);
        len += print_int(n);
        break;
    case 'i':
        n = va_arg(ap, int);
        len += print_int(n);
        break;
    case 'u':
        n = va_arg(ap, unsigned int);
        len += print_unsigned(n);
        break;
    case 'o':
        n = va_arg(ap, unsigned int);
        len += print_octal(n);
        break;
    case 'x':
        n = va_arg(ap, unsigned int);
        len += print_hex(n, 0);
        break;
    case 'X':
        n = va_arg(ap, unsigned int);
        len += print_hex(n, 1);
        break;
    case 'b':
        n = va_arg(ap, unsigned int);
        len += print_binary(n);
        break;
    case 'p':
        p = va_arg(ap, void *);
        len += print_pointer(p);
        break;
    case '%':
        len += print_char('%');
        break;
    default:
        len += print_char('%');
        len += print_char(*fmt);
        break;
    }
    return (len);
}

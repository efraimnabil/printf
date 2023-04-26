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
            len += write(1, s, strlen(s));
            break;
        case 'c':
            c = (char)va_arg(ap, int);
            len += write(1, &c, 1);
            break;
        case 'd':
        case 'i':
            n = va_arg(ap, int);
            len += print_int(n, *fmt);
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
        case 'X':
            n = va_arg(ap, unsigned int);
            len += print_hex(n, *fmt == 'X');
            break;
        case 'b':
            n = va_arg(ap, unsigned int);
            len += print_binary(n);
            break;
        case 'p':
            p = va_arg(ap, void *);
            len += print_pointer(p);
            break;
        default:
            len += write(1, fmt, 1);
            break;
    }
    return (len);
}

#include "main.h"

/**
 * is_alpha - Checks if a character is an alphabetic character.
 *
 * @c: The character to check.
 *
 * Return: 1 if @c is an alphabetic character, 0 otherwise.
 */
int is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * handle_percent - Handles the conversion specifiers for printf.
 *
 * @fmt: Format specifier.
 * @ap: List of arguments to parse.
 *
 * Return: Number of characters printed.
 */
int handle_percent(const char *fmt, va_list ap)
{
	int len = 0;
	char *s;
	char c;
	int n;
	void *p;

	if (is_alpha(*fmt))
	{
		switch (*fmt)
		{
			case 's':
				s = va_arg(ap, char *);
				if (s == NULL)
					s = "(null)";
				len += write(1, s, strlen(s));
				break;
			case 'c':
				c = (char)va_arg(ap, int);
				len += write(1, &c, 1);
				break;
			case 'd':case 'i':case 'u':case 'x':case 'X':case 'o':case 'b':
				n = va_arg(ap, int);
				len += print_int(n, *fmt);
				break;
			case 'p':
				p = va_arg(ap, void *);
				len += print_pointer(p);
				break;
			default:
				len += write(1, "%%", 1);
				len += write(1, fmt, 1);
				break;
		}
	}
	else if (*fmt == '%')
		len += write(1, "%%", 1);
	else
		len += write(1, "%%", 1), len += write(1, fmt, 1);

	return (len);
}

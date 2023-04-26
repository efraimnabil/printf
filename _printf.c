#include "main.h"

/**
 * _printf - function that prints formatted output to stdout
 * @fmt: string containing the format specifiers
 *
 * Return: the number of characters printed
 */
int _printf(const char *fmt, ...)
{
	va_list ap;
	int len = 0;
	char *s;
	char c;

	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			switch (*fmt)
			{
				case '%':
					len += write(1, "%", 1);
					break;
				case 's':
					s = va_arg(ap, char *);
					len += write(1, s, strlen(s));
					break;
				case 'c':
					c = va_arg(ap, int);
					len += write(1, &c, 1);
					break;
			}
		}
		else
		{
			len += write(1, fmt, 1);
		}
		fmt++;
	}
	va_end(ap);

	return (len);
}

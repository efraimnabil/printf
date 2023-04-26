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
	int len = 0, prev_per = 0;

	va_start(ap, fmt);

	if (fmt == NULL)
		return (-1);

	while (*fmt)
	{
		if (prev_per)
		{
			if (*fmt != ' ')
			{
				len += handle_percent(fmt, ap);
				prev_per = 0;
			}
		}
		else
		{
			if (*fmt == '%')
			{
				prev_per = 1;
			}
			else
			{
				len += write(1, fmt, 1);
			}
		}
		fmt++;
	}

	if (prev_per)
	{
		return (-1);
	}

	va_end(ap);

	return (len);
}

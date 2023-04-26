#include "main.h"

/**
 * _printf - function that prints formatted output to stdout
 * @fmt: string containing the format specifiers
 *
 * Return: the number of characters printed
 */

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

/**
 * handle_percent - function that handles the "%" character
 * @fmt: the format string
 * @ap: the arguments list
 *
 * Return: the number of characters printed
 */
int handle_percent(char *fmt, va_list ap)
{
	int len = 0;
	char *s;
	char c;

	fmt++;
	if (*fmt == 's')
	{
		s = va_arg(ap, char *);
		len += print_string(s);
	}
	else if (*fmt == 'c')
	{
		c = va_arg(ap, int);
		len += print_char(c);
	}
	else if (*fmt == '%')
	{
		len += print_char('%');
	}
	return (len);
}

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
			len += handle_percent((char *)fmt, ap);
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

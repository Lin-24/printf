#include "mainn.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - Writes a character to stdout
 * @c: The character to be written
 * Return: On success, returns the number of characters written.
 * On error, returns -1 and sets errno appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - Prints output according to a format.
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					printed_chars += _putchar(va_arg(args, int));
					break;
				case 's':
					printed_chars += _print_string(va_arg(args, char *));
					break;
				case '%':
					printed_chars += _putchar('%');
					break;
				case 'd':
				case 'i':
					printed_chars += _print_integer(va_arg(args, int));
					break;
				case 'b':
					printed_chars += _print_binary(va_arg(args, unsigned int));
					break;
				default:
					printed_chars += _putchar('%') + _putchar(*format);
					break;
			}
		}
		else
		{
			printed_chars += _putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}

/**
 * _print_string - Prints a string to stdout.
 * @str: The string to be printed
 *
 * Return: The number of characters printed.
 */
int _print_string(char *str)
{
	int printed_chars = 0;

	if (str == NULL)
		str = "(null)";

	while (*str != '\0')
	{
		printed_chars += _putchar(*str);
		str++;
	}

	return (printed_chars);
}

/**
 * _print_integer - Prints an integer to stdout.
 * @num: The integer to be printed
 *
 * Return: The number of characters printed.
 */
int _print_integer(int num)
{
	unsigned int abs_num = num;
	int printed_chars = 0;

	if (num < 0)
	{
		printed_chars += _putchar('-');
		abs_num = -num;
	}

	if (abs_num / 10)
		printed_chars += _print_integer(abs_num / 10);

	printed_chars += _putchar('0' + (abs_num % 10));

	return (printed_chars);
}

/**
 * _print_binary - Prints an unsigned integer in binary format.
 * @num: The unsigned integer to be printed
 *
 * Return: The number of characters printed.
 */
int _print_binary(unsigned int num)
{
	int printed_chars = 0;

	if (num / 2)
		printed_chars += _print_binary(num / 2);

	printed_chars += _putchar('0' + (num % 2));

	return (printed_chars);
}


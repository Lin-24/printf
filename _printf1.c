#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Produces output according to a format
 * @format: character string specifying the format
 *
 * Return: No. of  characters printed excluding the null byte and -1 on error
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'd':
				case 'i':
					printed_chars += printf("%d", va_arg(args, int));
					break;

				default:
					putchar('%');
					putchar(*format);
					printed_chars += 2;
					break;
			}
		}
		else
		{
			putchar(*format);
			printed_chars++;
		}

		format++;
	}

	va_end(args);

	return (printed_chars);
}

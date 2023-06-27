#include "main.h"

/**
 * _printf - My printf function
 * @format: format of the output
 * Return: No. of characters printed excluding the ending null byte(\n)
 */
int _printf(const char *format, ...)

{
	char *str;
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
		switch (*format)
		{
			case 'c':
				count += _putchar(va_arg(args, int));
				break;
			case 's':
				str = va_arg(args, char *);
				count += _puts(str);
				break;
			case '%':
				count += _putchar('%');
				break;
			case 'd':
			case 'i':

			default:
				count += _putchar('%');
				count += _putchar(*format);
				break;
		}
		}
		else
		{
			count += _putchar(*format);
		}

		format++;
	}

	va_end(args);

	return (count);
}

/**
 * _puts - Prints a string to stdout
 * @str: The string to be printed
 * Return: The number of characters printed
 */
int _puts(char *str)
{
	int k = 0;

	while (str[k])
	{
		_putchar(str[k]);
		k++;
	}
	return (k);
}


/**
 * _putchar - Prints a character to stdout
 * @c: The character to be printed
 * Return: On success, the character written. On error, -1 is returned.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

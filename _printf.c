#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - my printf function
 * @format: format of the output
 *
 * Return: number of characters printed (excluding  ending null byte)
 */

int _printf(const char *format, ...)

{

	va_list list;
	int i = 0, j, count = 0;

	va_start(list, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				_putchar(va_arg(list, int));
				count++;
			}
			else if (format[i + 1] == 's')
			{
				char *string;

				string = va_arg(list, char *);
				for (j = 0; string[j]; j++)
					_putchar(string[j]), count++;
			}
			else if (format[i + 1] == '%')
			{
				_putchar('%'), count++;
			}
			i++;
		}
		else
			_putchar(format[i]), count++;
		i++;
	}

	a_end(list);
	return (count);
}

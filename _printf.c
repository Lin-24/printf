#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Printf function
 * @format: format
 * Return: Printed chars
 */

int _printf(const char *format, ...)
{
        va_list args;
        int length = 0;

        va_start(args, format);

        while (*format != '\0')
        {
                if (*format == 'c')
                {
                        char chr = (char)va_arg(args, int);

                        putchar(chr);
                        ++length;
                        }
                else if (*format == 's')
                {
                        char *str = va_arg(args, char*);

                        for (int i = 0; str[i] != '\0'; ++i)
                        {
                                putchar(str[i]);
                                ++length;
                        }
                }
                else if (*format == '%')
                {
                        putchar('%');
                        ++length;
                }
                else
                {
                        putchar(*format);
                        ++length;
                }
                ++format;
        }
        va_end(args);
        return (length);
}

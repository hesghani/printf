#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/* Function prototypes */
int print_char(int c);
int print_str(char *str);

/**
 * _printf - Our custom printf function.
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
int count = 0;
va_list args;

va_start(args, format);

while (*format)
{
if (*format != '%')
{
write(1, format, 1);
count++;
}
else
{
format++;

if (*format == '\0')
break;

if (*format == 'c')
count += print_char(va_arg(args, int));
else if (*format == 's')
count += print_str(va_arg(args, char *));
else if (*format == '%')
{
write(1, "%", 1);
count++;
}
else
{
write(1, "%", 1);
write(1, format, 1);
count += 2;
}
}
format++;
}

va_end(args);
return (count);
}

/**
 * print_char - Print a character.
 * @c: The character to print.
 *
 * Return: 1 (the number of characters printed).
 */
int print_char(int c)
{
write(1, &c, 1);
return (1);
}

/**
 * print_str - Print a string.
 * @str: The string to print.
 *
 * Return: The number of characters printed.
 */
int print_str(char *str)
{
int count = 0;

if (str == NULL)
str = "(null)";

while (*str)
{
write(1, str, 1);
str++;
count++;
}

return (count);
}


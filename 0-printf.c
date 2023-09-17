#include "main.h"
#include <stdarg.h>
#include <unistd.h>

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
{
int c = va_arg(args, int);
write(1, &c, 1);
count++;
}
else if (*format == 's')
{
char *str = va_arg(args, char *);
if (str == NULL)
str = "(null)";
while (*str)
{
write(1, str, 1);
str++;
count++;
}
}
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


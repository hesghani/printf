#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

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
format++; /* Move past '%' */
if (*format == 'c')
{
char c = va_arg(args, int);
write(1, &c, 1);
count++;
}
else if (*format == 's')
{
char *s = va_arg(args, char *);
if (s == NULL)
s = "(null)";
while (*s)
{
write(1, s, 1);
s++;
count++;
}
}
else if (*format == 'd' || *format == 'i')
{
int num = va_arg(args, int);
/* Convert integer to a string and print it */
char buffer[12]; /* Assuming 32-bit int */
int length = snprintf(buffer, sizeof(buffer), "%d", num);
write(1, buffer, length);
count += length;
}
else if (*format == '%')
{
write(1, "%", 1);
count++;
}
}
format++;
}

va_end(args);
return (count);
}


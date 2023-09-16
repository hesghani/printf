#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int _printf(const char *format, ...)
{
int count = 0;
va_list args;

va_start(args, format);

while (*format)
{
if (*format != '%')
{
/* If not a format specifier, print the character */
write(1, format, 1);
count++;
}
else
{
format++; /* Move past '%' */

if (*format == '\0')
break; /* Format string ends with '%', stop processing */

if (*format == 'c')
{
/* Handle character specifier */
int c = va_arg(args, int);
write(1, &c, 1);
count++;
}
else if (*format == 's')
{
/* Handle string specifier */
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
/* Handle '%' specifier */
write(1, "%", 1);
count++;
}
else
{
/* Invalid format specifier, ignore it */
write(1, "%", 1); /* Print the '%' character */
write(1, format, 1); /* Print the invalid character */
count += 2;
}
}
format++;
}

va_end(args);
return (count);
}

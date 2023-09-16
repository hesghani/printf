#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

static void print_char(int c, int *count) {
write(1, &c, 1);
(*count)++;
}

static void print_str(const char *str, int *count) {
if (str == NULL)
str = "(null)";
while (*str) {
write(1, str, 1);
str++;
(*count)++;
}
}

int _printf(const char *format, ...) {
int count = 0;
va_list args;

va_start(args, format);

while (*format) {
if (*format != '%') {
/* If not a format specifier, print the character */
print_char(*format, &count);
} else {
format++; /* Move past '%' */

if (*format == '\0')
break; /* Format string ends with '%', stop processing */

if (*format == 'c') {
/* Handle character specifier */
int c = va_arg(args, int);
print_char(c, &count);
} else if (*format == 's') {
/* Handle string specifier */
char *str = va_arg(args, char *);
print_str(str, &count);
} else if (*format == '%') {
/* Handle '%' specifier */
print_char('%', &count);
} else {
/* Invalid format specifier, ignore it */
print_char('%', &count); /* Print the '%' character */
print_char(*format, &count); /* Print the invalid character */
count += 2;
}
}
format++;
}

va_end(args);
return count;
}

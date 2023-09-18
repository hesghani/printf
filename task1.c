#include "main.h"
#include <stdarg.h>

int print_int(va_list args, char buffer[],
              int flags, int width, int precision)
{
    int n = va_arg(args, int);
    int chars_written = 0;
    int is_negative = (n < 0);
    char temp_buffer[32];  /* Assuming a maximum of 32 digits */
    int temp_chars = 0;

    /* Silence the unused parameter warning */
    (void)precision;

    if (is_negative)
        n = -n;

    do
    {
        temp_buffer[temp_chars++] = '0' + (n % 10);
        n /= 10;
    } while (n > 0);

    if (is_negative)
        buffer[chars_written++] = '-';
    
    while (temp_chars > 0)
        buffer[chars_written++] = temp_buffer[--temp_chars];

    while (chars_written < width)
        buffer[chars_written++] = (flags & F_ZERO) ? '0' : ' ';

    return chars_written;
}


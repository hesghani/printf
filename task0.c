#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
    va_list args;
    char buffer[BUFF_SIZE];
    int chars_written = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            buffer[chars_written++] = *format;
        }
        else
        {
            /* Handle format specifiers and call corresponding print functions here */
            format++; /* Move past '%' */
            if (*format == '\0') /* Check for format specifier at the end */
                break;

            /* Example: Handle 'c' specifier */
            if (*format == 'c')
            {
                /* Placeholder for handling 'c' specifier */
                char c = va_arg(args, int);
                buffer[chars_written++] = c;
            }
            /* Add similar logic for other specifiers */
        }
        format++; /* Move to the next character in the format string */
    }

    va_end(args);

    /* Write the contents of 'buffer' to stdout using 'write' */
    write(1, buffer, chars_written);

    return chars_written;
}


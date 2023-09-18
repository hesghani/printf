#include "main.h"

int _printf(const char *format, ...)
{
    int printed_chars = 0;
    va_list args;

    char buffer[BUFF_SIZE] = {0};
    int i = 0, flags = 0, width = 0, precision = 0, size = 0;

    va_start(args, format);
    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '\0')
                break;
            parse_format(format, &i, &flags, &width, &precision, &size);
            printed_chars += print_specifier(format[i], args, buffer, flags, width, precision, size);
        }
        else
        {
            buffer[printed_chars++] = format[i++];
        }
    }
    va_end(args);

    write(1, buffer, printed_chars);

    return printed_chars;
}

void parse_format(const char *format, int *i, int *flags, int *width, int *precision, int *size)
{
    UNUSED(format);
    UNUSED(i);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    /* Implement the parsing logic for format specifiers here */
    /* Set appropriate values for flags, width, precision, and size */
}

int print_specifier(char specifier, va_list args, char buffer[], int flags, int width, int precision, int size)
{
    UNUSED(specifier);
    UNUSED(args);
    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    /* Implement the logic to handle different specifiers here */
    /* Modify the buffer as needed and return the number of characters printed */
    return 0;
}


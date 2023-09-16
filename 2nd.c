#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/* Function prototypes */
int print_char(va_list args);
int print_str(va_list args);
int print_int(va_list args);

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
                count += print_char(args);
            else if (*format == 's')
                count += print_str(args);
            else if (*format == 'd' || *format == 'i')
                count += print_int(args);
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
 * @args: The va_list containing the character to print.
 *
 * Return: 1 (the number of characters printed).
 */
int print_char(va_list args)
{
    int c = va_arg(args, int);
    write(1, &c, 1);
    return (1);
}

/**
 * print_str - Print a string.
 * @args: The va_list containing the string to print.
 *
 * Return: The number of characters printed.
 */
int print_str(va_list args)
{
    char *str = va_arg(args, char *);
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

/**
 * print_int - Print an integer.
 * @args: The va_list containing the integer to print.
 *
 * Return: The number of characters printed.
 */
int print_int(va_list args)
{
    int n = va_arg(args, int);
    int count = 0;
    int divisor = 1;

    if (n < 0)
    {
        write(1, "-", 1);
        count++;
        divisor = -divisor;
        n = -n;
    }

    while (n / divisor > 9)
        divisor *= 10;

    while (divisor != 0)
    {
        char digit = n / divisor + '0';
        write(1, &digit, 1);
        count++;
        n %= divisor;
        divisor /= 10;
    }

    return (count);
}


#include "main.h"

/**
 * print_char - Prints a character
 * @args: The variable arguments
 * @buffer: The buffer to store the output
 * @flags: The formatting flags
 * @width: The width specifier
 * @precision: The precision specifier
 * @size: The size specifier
 *
 * Return: The number of characters printed
 */
int print_char(va_list args, char buffer[], int flags, int width, int precision, int size)
{
    char c = va_arg(args, int);

    (void)flags; /* Unused */
    (void)width; /* Unused */
    (void)precision; /* Unused */
    (void)size; /* Unused */

    buffer[0] = c;
    return (1);
}


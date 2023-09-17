#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h> /* Include the <stdio.h> header */

/* Function prototypes */
int print_char(int c);
int print_str(char *str);
int print_int(int num);

/* Comment out or remove the _printf function for Task 1 */
/*
int _printf(const char *format, ...)
{
    // ...
}
*/

/* Implement the print_int function for Task 1 */
int print_int(int num)
{
    int count = 0;
    char buffer[12]; /* Assuming 32-bit int */
    int length = snprintf(buffer, sizeof(buffer), "%d", num);

    write(1, buffer, length);
    count += length;

    return (count);
}

/* Implement other functions as needed for Task 1 */



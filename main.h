#ifndef _PRINTF_H_
#define _PRINTF_H_

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)

#define BUFF_SIZE 1024

#define F_PLUS    1
#define F_SPACE   2
#define F_HASH    4
#define F_ZERO    8
#define F_MINUS  16

typedef struct print_func
{
    char specifier;
    int (*func)(va_list, char *, int, int, int, int);
} print_func_t;

int _printf(const char *format, ...);

void parse_format(const char *format, int *i, int *flags, int *width, int *precision, int *size);
int print_unknown_specifier(char buffer[], char specifier);

int print_char(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_int(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_unsigned(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_string_custom(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_pointer(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_hex(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_octal(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_percent(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_reverse(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_rot13(va_list args, char buffer[], int flags, int width, int precision, int size);

int print_specifier(char specifier, va_list args, char buffer[], int flags, int width, int precision, int size);

#endif /* _PRINTF_H_ */


#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* Function prototypes */
int print_char(int c);
int print_str(char *str);
int print_int(int num);
int _printf(const char *format, ...);

#endif /* MAIN_H */

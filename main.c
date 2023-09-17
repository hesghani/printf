#include "main.h"

int main(void)
{
    int len;

    len = _printf("Let's try %c, %s, %d, and %i format specifiers.\n", 'A', "string", 42, -123);
    _printf("Length:[%d]\n", len);

    return (0);
}


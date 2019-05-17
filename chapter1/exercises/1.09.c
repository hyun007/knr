#include <stdio.h>

/* write a prgoram to copy its input to its output, replacing each string of
 * one or more blanks by a single blank */
int main()
{
    int c, last;

    do {
        c = getchar();
        if (c != EOF && !(c == ' ' && last == ' '))
            putchar(c);
        last = c;
        
    } while (c != EOF);

    return 0;
}

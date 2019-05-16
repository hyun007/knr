#include <stdio.h>

#define MAX  80 /* this is the max size of the histogram bar */
#define START ' '
#define END '~'

/* exercise 1-14: Write a program to print a histogram of the frequencies of 
 * different characters in its input. */
int main()
{
    int c, i, charset;

    charset = END - START + 1;
    int histogram[charset];

    for (i = 0; i < charset; ++i)
        histogram[i] = 0;
    
    while ((c = getchar()) != EOF) {
        if (c >= START && c <= END)
            ++histogram[c - START];
    }

    for (i = 0; i < charset; ++i) {
        printf("[%c]: ", i + START);
        int j;

        int max, overflow;
        if (histogram[i] < MAX) {
            max = histogram[i];
            overflow = 0;
        } else {
            max = MAX;
            overflow = 1;
        }

        for (j = 0; j < max; ++j)
            printf("#");

        if (overflow == 1)
            printf("+[%d]", histogram[i]);
        printf("\n");
    }

    return 0;
}

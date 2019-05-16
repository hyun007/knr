#include <stdio.h>

#define IN  1 /* inside a word */
#define OUT 0 /* outside a word */

/* exercise 1-13: Write a program to print a histogram of the lengths of words
 * in its input. It is easy to draw the histogram with the bars horizontal; a
 * vertical orientation is more challenging */
int main()
{
    int c, i, state, wordlen, longest, tallest;
    int histogram[30];
    
    state = OUT;
    wordlen = longest = tallest = 0;

    for (i = 0; i < 30; ++i)
        histogram[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                ++histogram[wordlen];
            }
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            wordlen = 0;
        } else if (state == IN) {
            ++wordlen;
        }
    }

    for (i = 0; i < 30; ++i) {
        if (histogram[i] > 0)
            longest = i;
        if (histogram[i] > tallest)
            tallest = histogram[i];
    }

    for (i = tallest; i > 0; --i) {
        printf("%2d| ", i);
        int j;
        for (j = 0; j <= longest; ++j) {
            if (histogram[j] >= i)
                printf(" # ");
            else
                printf("   ");
        }
        printf("\n");
    }

    printf("   ");
    for (i = 0; i <= longest; ++i)
        printf("---");
    
    printf("\n    ");

    for (i = 0; i <= longest; ++i)
        printf("%2d ", i+1);
    
    printf("\n");

    return 0;
}

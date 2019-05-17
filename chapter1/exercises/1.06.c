#import <stdio.h>

int main()
{
    int c;
    c = getchar() != EOF;
    printf("c = getchar() != EOF: %d\n", c);

    return 0;
}

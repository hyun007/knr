#include <stdio.h>
#include "stringutils.c"
#define MAXLINE 5000
/*
 * K&R Exercise 1-22 break up long lines 
 */

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = readline(line, MAXLINE)) > 0){
        wrap(line, 40);
        printf("%s", line);
    }
    return 0;
}

#include <stdio.h>
#include "stringutils.c"
#define MAXLINE 50
/*
 * K&R Chapter 1 Exercise 1-21. Write a program entab that replaces strings of 
 * blanks by the minimum number of tabs and blanks to achieve the same spacing.
 * Use the same tab stops as for detab. When either a tab or a single blank 
 * would suffice to reach a tab stop, which should be givin preference?
 *
 */

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = readline(line, MAXLINE)) > 0){
        entab(line, 4);
        printf("%s", line);
    }
    return 0;
}

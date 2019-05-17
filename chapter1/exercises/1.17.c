#include <stdio.h>
#define MAXLINE 50    /* maximum input line size */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* exercise 1-17 whire a program to print all input lines that are longer than 
 * 80 characters. */
int main()
{
    int len;                /* current line length */
    char line[MAXLINE];     /* current input line */

    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > MAXLINE)
            printf("%s", line);
    return 0;
}

/* getline: read a line into s, return length */
int get_line(char s[], int lim)
{
    int c, i, j;

    for (j=i=0; (c=getchar())!=EOF && c!='\n'; ++i) {
        if (i < lim - 1) {
            j = i;
            s[j] = c;
        }
    }
    if (c == '\n') {
        s[j] = c;
        ++i;
        ++j;
    }
    s[j] = '\0';
    return i;
}

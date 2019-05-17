#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

int get_line(char line[], int maxline);

/* exercise 1-18: write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blank lines. */
int main()
{
    int len;                /* current line length */
    char line[MAXLINE];     /* current input line */

    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > 1)
            printf("%s", line);
    return 0;
}

/* getline: read a line into s, return length */
int get_line(char s[], int lim)
{
    int c, i, trim;

    for (trim=i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
        s[i] = c;
        if (c != ' ' && c != '\t')
            trim = i;
    }
    if (c == '\n') {     
        s[i] = c;
        ++i;
    }
    if (trim+1 < i) {
        s[trim+1] = '\n';      
        s[trim+2] = '\0';      
    }
    else
        s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
     

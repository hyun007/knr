#include <stdio.h>
#define MAXLINE 50    /* maximum input line size */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* exercise 1-16 revise the main routine of the longest-line program so it 
 * will correctly print the length of arbitrarily long input lines, and as 
 * much as possible of the text. */
int main()
{
    int len;                /* current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len >= max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)        /* there was a line */
        printf("[%d]: %s", max, longest);
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

#include <stdio.h>
#include "stringutils.c"
#define MAXLINE 50

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

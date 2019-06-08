#include <stdio.h>
#define IN 1
#define OUT 0

/* string maniplations written so far during chapter 1 of k&r */

int readline(char line[], int max);
void copy(char to[], char from[]);
void entab(char line[], int width);
void detab(char line[], int width);

/* getline: read a line into s, return length */
int readline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume 'to' is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

/* entab: replace "width" number of spaces with tabs */
void entab(char line[], int width)
{
    int size, space_counter, i, j;
    for(i=0; line[i] != '\0'; ++i)
        size = i;
    char temp[size+10], test_char;
    for(i=j=space_counter=0; line[i] != '\0'; ++i) {
        test_char = line[i];
        if(test_char == ' ') {
            space_counter++;
            if(space_counter == width) {
                j = j-width+1;
                test_char = '\t';
                space_counter = 0;
            }
        } else {
            space_counter = 0;
        }
        temp[j] = test_char;
        ++j;
    }
    temp[j] = '\0';
    copy(line, temp);
}

/* detab: replace tab characters with "width" number of spaces */
void detab(char line[], int width)
{
    int size, i, j, k;
    for(i=size=0; line[i] != '\0'; ++i)
        size = i;
    ++size;
    char temp[size+width*10], test_char;
    for(i=j=0; line[i] != '\0'; ++i) {
        test_char = line[i];
        if(test_char == '\t') {
            for(k=0;k<width;++k) {
                temp[j] = ' ';
                ++j;
            }
            --j;
        } else {
            temp[j] = test_char;
        }
        ++j;
    }
    temp[j] = '\0';
    copy(line, temp);
}

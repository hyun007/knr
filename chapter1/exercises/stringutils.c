#include <stdio.h>
#define IN 1
#define OUT 0

/* string maniplations written so far during chapter 1 of k&r */

int readline(char line[], int max);
void copy(char to[], char from[]);
void entab(char line[], int width);
void detab(char line[], int width);
void wrap(char line[], int width);

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
    int s, i, j;
    for(i=1; line[i] != '\0'; ++i);
    char temp[i];
    for(i=j=s=0; line[i] != '\0'; ++i) {
        if(line[i] == ' ') {
            ++s;
	    } else {
            while(s > 0){
                if (s>=width){
                    temp[j] = '\t';
                    s = s - width;
                } else {
                    temp[j] = ' ';
                    --s;
                }
                ++j;
            }
            temp[j] = line[i];
            ++j;
	    }
    }
    temp[j] = '\0';
    copy(line, temp);
}

/* detab: replace tab characters with "width" number of spaces */
void detab(char line[], int width)
{
    int i, j, k;
    for(i=1; line[i] != '\0'; ++i);
    char temp[i*width];
    for(i=j=0; line[i] != '\0'; ++i) {
        if(line[i] == '\t') {
            for(k=0;k<width;++k) {
                temp[j] = ' ';
                ++j;
            }
        } else {
            temp[j] = line[i];
            ++j;
        }
    }
    temp[j] = '\0';
    copy(line, temp);
}

/* long_lines: break lines at a whitespace character right before the limit */
void wrapi(char line[], int width)
{
    int i, j, k;
    for(i=1; line[i] != '\0'; ++i);
    j = i/width-1;
    if(i%width>0)++j;

    for(;j>0;--j) {
        for(k=width*j;k>width*(j-1);--k){
            if(line[k]==' '){
                line[k] = '\n';
                break;
            }
        }
    }
}

void wrap(char line[], int width)
{
    int i,j,k;
    i=j=k=0;
    while(line[i] != '\0') {
        if(line[i] == ' ')j=i;
        if(k>=width){
            line[j]='\n';
            k=i-j;
        } else {
            ++k;
        }
        ++i;
    }
}

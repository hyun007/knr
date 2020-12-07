#include <stdio.h>
#include "stringutils.c"
#define MAXLINE 5000
/*
 * K&R Exercise 1-23 remove comments
 */

int main()
{
    char c, lc, llc, lllc;
    lc=llc=lllc=' ';
    int sc, mc, fc;
    sc=mc=fc=0;
    while ((c=getchar())!=EOF){
        if(lc=='/' && c=='/') sc=1;
        if(lc=='/' && c=='*') mc=1;
        if(sc==1 && lc=='\n') sc=0;
        if(mc==1 && lllc=='*' && llc=='/') mc=0;
        if(sc==0 && mc==0 && fc>0) putchar(lc);
        lllc=llc;
        llc=lc;
        lc=c;
        ++fc;
    }
    putchar(lc);
    return 0;
}

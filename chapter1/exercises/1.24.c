#include <stdio.h>
/*
 * K&R Exercise 1-24 validate c program for matching braces, quotes etc... 
 */
int enter(char open, char prev, int depth);
int is_open(char c);
int is_close(char c);
char get_close(char open);
int line_num, col;
int in_mcom, in_scom, in_single, in_double, in_esc;

int main()
{
    int depth;
    line_num = 1;
    col = 0;
    in_mcom=in_scom=in_single=in_double=in_esc=0;
    depth = enter('\0', '\0', 0);
    if(depth!=0) {
        printf("this file has errors. depth: %d", depth);
    } else {
        printf("this file is valid %d", depth);
    }
    return 0;
}

int enter(char open, char prev, int depth)
{
    char c;
    if(open=='\'') in_single = 1;
    if(open=='\"') in_double = 1;
    while((c=getchar())!=EOF) {
        ++col;
        if(!in_esc && c=='\\') {
            in_esc = 1;
            continue;
        }
        if(in_esc) {
            in_esc=0;
            continue;
        }
        if(!in_single & !in_double && is_open(c)) {
            printf("loc+: %d,%d depth+: %d open+:%c\n", line_num, col, depth+1, c);
            depth = enter(c, prev, depth+1);
        }
        else if(c==get_close(open)) {
            if(in_single) in_single = 0;
            if(in_double) in_double = 0;
            printf("line+: %d,%d depth-: %d close-:%c\n", line_num, col, depth-1, c);
            return depth - 1;
        }
        else if(!in_single && !in_double && is_close(c)) {
            printf("line+: %d,%d depth-: %d close-:%c\n", line_num, col, depth-1, c);
            return depth - 1;
        }
        else if(c=='\n') {
            ++line_num;
            col = 0;
        }
    }
    printf("file EOF\n");
    return depth;
}

int is_open(char c)
{
    if(c=='{') return 1;
    if(c=='(') return 1;
    if(c=='[') return 1;
    if(c=='\'') return 1;
    if(c=='\"') return 1;
    if(c=='\0') return 1;
    return 0;
}

int is_close(char c)
{
    if(c=='}') return 1;
    if(c==')') return 1;
    if(c==']') return 1;
    if(c=='\'') return 1;
    if(c=='\"') return 1;
    if(c==EOF) return 1;
    return 0;
}

char get_close(char open)
{
    if(open=='{') return '}';
    if(open=='(') return ')';
    if(open=='[') return ']';
    if(open=='\'') return '\'';
    if(open=='\"') return '\"';
    if(open=='\0') return EOF;
    return EOF;
}

#include<stdio.h>
//#include<math.h>
int main()
{
    int test, min, max;
    min=0;
    max=2;
    for(test=0;test<30;++test) {
        max=max*2;
        printf("%d\n", max);
    }
    //printf("int: min:%d, max%d\n", min, max);
    /*int test;
    test=pow(2,4*sizeof(test));
    ++test;
    ++test;
    ++test;
    ++test;
    test=test+test;*/
    printf("int size: %lu, max:%d", sizeof(test), test);
    return 0;
}

#import <stdio.h>

int main()
{
    printf("[SPACE]: 0x%x\n", ' ');
    printf("      ~: 0x%x\n", '~');
    printf("  total: 0x%x\n", '~' - ' ' + 1);

    return 0;
}

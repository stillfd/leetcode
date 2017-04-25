#include<stdio.h>

int addDigits(int num)
{
    return num - (num - 1) / 9 * 9;
}

void main(void)
{
    int a;
    scanf("%d", &a);
    int r = addDigits(a);
    printf("%d\r\n", r);
    return;
}

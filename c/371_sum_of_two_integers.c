#include<stdio.h>

int getSum(int a, int b)
{

    while(b)
    {
        int c = a & b;
        a = a ^ b;
        b = c << 1;
    }
    return a;
}

void main(void)
{
    int a = 3; 
    int b = 1;
    int r = getSum(a, b);
    printf("%d\r\n", r);
    return;
}

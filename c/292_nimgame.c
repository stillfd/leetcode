#include<stdio.h>

int canWinNim(int n)
{
    return n%4!=0;
}

void main(void)
{
    int n = 4;
    printf("%d", canWinNim(n));
    return;
}

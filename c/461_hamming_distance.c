#include<stdio.h>

int hammingDistance(int x, int y)
{
    int result = x^y;
    int ct = 0;
    while(result > 0)
    {
        printf("%d", result);
        if((result >> 1) * 2 + 1 ==  result)
        {
            ct++;
        }
        result = result >> 1;
    }
    return ct;
}



int main(void)
{
    int result = hammingDistance(1, 4);
    printf("the result is >> %d\r\n", result);
    return 0;
}

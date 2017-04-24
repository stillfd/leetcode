#include<stdio.h>


int findComplement(int nums)
{
    int i = 1;
    while(i <= nums)
    {
        i = i << 1;
    }
    return (i-1)^nums;
}


int main(void)
{
    int result = findComplement(5);
    printf("the result is >> %d\r\n", result);
    return 0;
}

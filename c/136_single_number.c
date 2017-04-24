#include<stdio.h>

int singleNumber(int* nums, int numsSize)
{
    int temp = 0;
    for(int i = 0; i< numsSize; i++)
    {
        temp ^= nums[i];
    }
    return temp;
}

int main(void)
{
    int nums[7] = {1, 2, 1, 3, 1, 2, 1};
    printf("%d\r\n", singleNumber(nums, 7));
    return 0;
}

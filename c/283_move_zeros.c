#include<stdio.h>

void moveZeroes(int* nums, int numsSize)
{
    int cnt = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(!nums[i])
        {
            cnt++;
        }
        else
        {
            nums[i - cnt] = nums[i];
        }
    }
    for(int i = numsSize - cnt; i < numsSize; i++)
    {
        nums[i] = 0;
    }
    return;
}

void main(void)
{
    int nums[5] = {0, 1, 0, 3, 12};
    moveZeroes(nums, 5);
    for(int i = 0; i < 5; i++)
    {
        printf("%d\r\n", nums[i]);
    }
    return;
}

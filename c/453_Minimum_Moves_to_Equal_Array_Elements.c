#include<stdio.h>
int minMoves(int* nums, int numsSize) {
    long int sum = 0;
    long int min = 0;
    if(numsSize == 1)
    {
        return 0;
    }
    min = nums[0];
    for(int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        if(min > nums[i])
        {
            min = nums[i];
        }
    }
    
    return sum -  min*numsSize;
}

void main(void)
{
    int nums[3] ={1, 1, 2147483647};
    int result = minMoves(nums, 3);
    printf("%d", result);
    return;
}
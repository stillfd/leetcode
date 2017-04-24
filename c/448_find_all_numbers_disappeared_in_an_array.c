#include<stdio.h>

int findDisappearedNumbers(int* nums, int numsSize, int* returnmat)
{
    for(int i = 0; i < numsSize; i++)
    {
        int idx = nums[i];
        if(idx < 0)
        {
            idx = -idx;
        }
        if(nums[idx-1] > 0) 
        {
            nums[idx-1] = -nums[idx-1];
        }
    }
    int cnt = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] > 0)
        {
            returnmat[cnt++] = i+1;
        }
    }
    return cnt;
}

void main(void)
{
    int nums[8] = {4,3,2,7,8,2,3,1};
    int returnMat[3]  = {0};
    int result =  findDisappearedNumbers(nums, 8, returnMat);
    for(int i = 0; i < result; i++)
    {
        printf("the %d th result is >> %d\r\n", i, returnMat[i]);
    }
    return;
}

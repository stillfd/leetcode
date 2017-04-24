#include<stdio.h>

int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize) {
     *returnSize = findNumsSize;
    int* result;
    result = (int *)malloc((*returnSize) * sizeof(int));
   
    int label;
    int max;
    for(int i = 0; i < findNumsSize; i++)
    {
        label  = 0;
        max    = -1;
        for(int j = 0; j < numsSize; j++)
        {
           // printf("%d",findNums[i]);
            //printf("%d",nums[j]);
            if(findNums[i] == nums[j])
            {
                label = 1;
            }
            //printf("%d",label);
            if(label && findNums[i] < nums[j])
            {
                max = nums[j];
                break;
            }
        }
        result[i] =  max;
    }
    return result;
}

int main(void)
{
    int findNums[3] = {4, 1, 2};
    int nums[4] = {1, 2, 3, 4};
    int *result;
    int returnSize = 0;
    result = nextGreaterElement(findNums, 3, nums, 4, &returnSize);

    for(int i = 0; i < returnSize; i++)
    {
        printf("%d\r\n", *result);
    }
    return 0;
}


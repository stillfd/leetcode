#include<stdio.h>

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int ct = 0;
    int max = 0;
    int sum = 0;
    for(int i = 0; i < numsSize; i++)
    {
       ct++;
       sum += nums[i];
       if(sum - ct)
       {
           ct = 0;
           sum = 0;
       }
        if(sum > max)
        {
            max = sum;
        }
    }
    return max;
}

void main(void)
{
    int sig[6] = {1,1,0,1,1,1};
    printf("%d\r\n", findMaxConsecutiveOnes(sig, 6));
    return;

}

#include<stdio.h>

void QuickSort(int st, int ed, int* array)
{
    int i = st;
    int j = ed;
    if(i >= j)
    {
        return;
    }

    int key =array[i];

    while(i < j)
    {
        while(i < j && key < array[j])
        {
            j--;
        }
        if(i < j)
        {
            array[i++] = array[j];
        }
        while(i < j && key > array[i])
        {
            i++;
        }
        if(i < j)
        {
            array[j--] = array[i];
        }
    }
    array[i] = key;
    QuickSort(st, i-1, array);
    QuickSort(i+1, ed, array);
    return;
}
int arrayPairSum(int* nums, int numSize)
{
    QuickSort(0, numSize-1, nums);
    // int tmp = nums[0] + nums[numSize-2];
    int tmp = 0;
    for(int i = 0; i < numSize; i = i+2)
    {
        tmp += nums[i];
    }
    return tmp;
}


int main(void)
{
    int nums[4] = {1, 4, 3, 2};
    int result = arrayPairSum(nums, 4);
    printf("the result is >> %d\r\n", result);
    return 0;
}

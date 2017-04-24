#include<stdio.h>
#include<string.h>

int find_loc(char target)
{
    if(target < 'a')
    {
        target = target + 'a'-'A';
    }
    char *keyboard[3] = {"qwertyuiop","asdfghjkl","zxcvbnm"};
    int loc = 0;
    for(int i = 0; i < 3; i++)
    {
        int j = 0;
        while(keyboard[i][j] != '\0')
        {
            if(keyboard[i][j] == target)
            {
                loc = i + 1;
                break;
            }
            j++;
        }
        if(loc)
        {
            break;
        }
    }
    return loc;
}

char** findWords(char** words, int wordsSize, int* returnSize) {
    *returnSize = 0;
    char** a;
    a = malloc(wordsSize*sizeof(char*));
    int pre;
    int cur;
    int inValid;
    for(int i = 0; i < wordsSize; i++)
    {
        int j = 0;
        inValid = 0;
        while( words[i][j] != '\0')
        {
            if(0 == j)
            {
                pre = find_loc(words[i][j]);
            }
            else
            {
                cur = find_loc(words[i][j]);
                if(cur != pre)
                {
                    inValid = 1;            
                    break;
                }
                pre = cur;
            }
            j++;
        }
        if(!inValid)
        {
            a[*returnSize] = malloc((j+1) * sizeof(char)); // need to add one incase of missing \0
            memcpy(a[*returnSize], words[i], j + 1);
            (*returnSize)++;
        }
    }
    return a;
}

int main(void)
{
    int nums[4] = {1, 4, 3, 2};
    int result = arrayPairSum(nums, 4);
    printf("the result is >> %d\r\n", result);
    return 0;
}

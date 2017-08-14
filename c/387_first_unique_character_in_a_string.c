#include<stdio.h>

int firstUniqChar(char* s)
{
    int dict[26] = {0};
    int i = 0;
    while(s[i] != '\0')
    {
        dict[s[i++] - 'a']++; 
    }

    i = 0;
    while(s[i] != '\0')
    {
        if(dict[s[i++] - 'a'] == 1)
        {
            return i-1;
        }
    }
    return -1;
}


void main(void)
{
    char* s = "loveleetcode";
    int r = firstUniqChar(s);
    printf("%d", r);
    return;
}

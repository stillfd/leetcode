#include<stdio.h>
#include<string.h>

void reverseWords(char* s)
{
    int len = strlen(s);
    
    int l = 0;
    int r, end;
    
    for(int i = 0; i <= len; i++)
    {
        if(s[i] == 32 || s[i] == '\0')
        {
            r =  i - 1;
            while( l < r)
            {
                char tmp = s[r];
                s[r] = s[l];
                s[l] = tmp;
                r--;
                l++;
            }
            l = i + 1;
        }
    }
    return;
}


int main(void)
{
    char s[] = "Let's take LeetCode Contest";
    reverseWords(s);
    printf("the result is >> %s\r\n", s);
    return 0;
}

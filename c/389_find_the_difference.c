#include<stdio.h>
#include<string.h>
char findTheDifference(char* s, char* t)
{
    int ls = strlen(s);
    
    int sum = 0;

    for(int i = 0; i < ls; i++)
    {
        sum -= s[i];
        sum += t[i];
    }
    sum += t[ls];
    return sum;
}

void main(void)
{
    char* s = "abcd";
    char* t = "abcde";
    char r = findTheDifference(s, t);

    printf("the result is >> %c\r\n",r);

    return;
}

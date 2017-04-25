#include<stdio.h>
#include<string.h>
int findLUSlength(char* a, char* b)
{
    int la = strlen(a);
    int lb = strlen(b);
   
    if(la < lb)
    {
        la = lb;
    }
    return strcmp(a,b)==0?-1:la;
}

void main(void)
{
    char* a = "abs";
    char* b = "cdc";
    int r = findLUSlength(a, b);
    printf("%d\r\n", r);
    return;
}

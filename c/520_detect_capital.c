#include<stdio.h>
#include<string.h>

int detectCapitalUse(char* word)
{
    int l = strlen(word);
    int ct = 0;
    int ct_C = 0;
    for(int i = 0; i < l; i++)
    {
        if(word[i]> 'a' && word[i] < 'z')
        {
            ct++;
        }
        else
        {
            ct_C++;
        }
    }
    printf("%d, %d", ct, l);
   if(ct_C == l || ct == l ||(ct_C == 1 && word[0] < 'a'))
   {
        return 1;
   }
   else
   {
        return 0;
   }
}


void main(void)
{
    char* word = "usa";
    printf("%d", detectCapitalUse(word));
    return;
}

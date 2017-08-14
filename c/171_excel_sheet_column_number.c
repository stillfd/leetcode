#include<stdio.h>
#include<string.h>

int titleToNumber(char* s)
{
    int sum = 0;
    int l = strlen(s);
    for(int i = 0; i < l; i++)
    {
        int p = l - i - 1;
        int power = 1;
        for( int j = 0; j < p; j++)
        {
             power *= 26;
        }
        sum += (s[i] - 'A' + 1) * power;
    }
    return sum;

}

void main(void)
{
    char* s = "AAB";
    int r = titleToNumber(s);
    printf("%d", r);
    return;
}

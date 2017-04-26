#include<stdio.h>
#include<string.h>

int canConstruct(char* ransomNote, char* magazine)
{
    int dict[26] = {0};
    for(int i = 0; i < strlen(ransomNote); i++)
    {
        dict[ransomNote[i] - 'a']++;
    }
    for(int i = 0 ; i < strlen(magazine); i++)
    {
        dict[magazine[i] - 'a']--;
    }
    for(int i = 0; i < 26; i++)
    {
        if(dict[i] > 0)
        {
            return 0;
        }
    }
    return 1;
}

void main(void)
{
    int result = canConstruct("aa","aab");
    printf("%d\r\n", result);
    return;
}

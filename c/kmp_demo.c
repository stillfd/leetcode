#include<stdio.h>
#include<string.h>
typedef char* string;

void GetNext(char* s, int* next)
{
	int n = strlen(s);
	int i = 0; 
	int j = -1;
	next[0] = -1;
	while(i < n)
	{
		if(-1 == j || s[i] == s[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j=next[j];
		}
	}
}

int kmp(char* s, char* t)
{
	int ls = strlen(s);
	int lt = strlen(t);
	int next[255] = {0};
	GetNext(t, next);
	int i = 0, j = -1;
	printf("j >> %d, t len %d\n", strlen(s), strlen(t));
	while(i < ls && j < lt)
	{
		if(j == -1|| s[i] == s[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
		printf("kmpserach >> j >> %d\n", j);
	}
	printf("j >> %d, t len %d\n", j, strlen(t));
	if(j == strlen(t))
		return 1;
	else
		return 0; 
}

int main(void)
{
	char* s = "ababababac\0";
	char* t = "ababac\0";
	int i = 0;
	int next[25];
	GetNext(t,next);
	for(;i< strlen(t); i++)
	{
		printf("%d\n",next[i]);
	}
	int res = kmp(s,t);
	printf("res >> %d\n", res);
	return 0;
}
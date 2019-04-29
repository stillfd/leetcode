#include<stdio.h>
typedef char* string;

void GetNext(string s, int* next)
{
	int i = 1; 
	int j = 0;
	next[1] = 0;
	while(i <s[0])
	{
		if(0 == j || s[i] == s[j])
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

int kmp(string s, string t)
{
	int next[255] = {0};
	GetNext(t, next);
	int i = 0, j = 0;
	while(i <= s[0] && j <= t[0])
	{
		if(j == 0|| s[i] == s[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	printf("j >> %d, t len %d\n", j, t[0]);
	if(j > t[0])
		return 1;
	else
		return 0; 
}

int main(void)
{
	char s[255] = " ababababac";
	s[0] = 10;
	char t[255] = " ababac";
	t[0] = 6;
	int i = 1;
	int next[25];
	GetNext(t,next);
	for(;i<= t[0]; i++)
	{
		printf("%d\n",next[i]);
	}
	int res = kmp(s,t);
	printf("res >> %d\n", res);
	return 0;
}
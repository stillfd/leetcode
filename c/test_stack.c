#include<stdio.h>
#include<stack.h>

stack<int> s;
void main(void)
{
    s.push('1');
    s.push('2');
    printf("%d\r\n", s.top());
    return;
}


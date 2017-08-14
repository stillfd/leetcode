/*demo of linked list written without assistance*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node *ptr;

struct node
{
    int val;
    ptr next;
};

void main(void)
{
    ptr head;
    ptr p1;
    int tmp  =1;
    for(int i = 0; i < 5; i++)
    {
        ptr tmpcell;
        tmpcell=malloc(sizeof(ptr));
        printf("\r\nplease input the %dth item >> ", i);
        flush();
        scanf("%d", &tmp);
        tmpcell->val = tmp;
        tmpcell->next = NULL;
        if(i == 0)
        {
            head = tmpcell;
            p1 = tmpcell;
        }
        else
        {
            p1->next = tmpcell;
            p1 = tmpcell;
        }        
    }

    printf("\r\n");    
    
    p1 = head;
    for(int i = 0; i < 5; i++)
    {
        printf("the %d th item is  %d \r\n", i, p1->val);
        p1 = p1->next;
    }
    return;
}

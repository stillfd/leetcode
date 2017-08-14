/*realization of stack in c with using list*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node* ptr;

typedef struct node{
    int val;
    ptr next;
}* stack;


void init(stack *s);

void frees(stack *s);

void push(stack s, int x);

int pop(stack s);

int top(stack s);

void main(void)
{
    stack s;
    printf("here comes the initialization of stack\r\n");
    init(&s);
    printf("here let us push 1, 2, 3 into the stack in order\r\n");
    push(s, 1);
    push(s, 2);
    push(s, 3);
    printf("here is the top of the stack %p\r\n", s);

    int t = top(s);
    printf("the top element in the stack is %d\r\n", t);
    t = pop(s);
    printf("poped >> %d\r\n", t);
    t = top(s);
    printf("top element after pop is %d\r\n", t);
    frees(&s);
    if(!s)
    {   
        printf("yes\r\n");
    }
    else
    {
        printf("no \r\n");
    }
    return;
}

void frees(stack *s)
{
	ptr p= *s;
	while((*s)->next)
	{
		p = (*s)->next;
		(*s)->next = p->next;
		free(p);
	}
	if(!(*s)->next)
	{
		printf("succeed free all the stack cells]\r\n");
	}
	(*s) = NULL;
	return;
}

void init(stack *s)
{
    *s = malloc(sizeof(struct node));
    (*s)->next = NULL;
    return;
}

void push(stack s, int x)
{
    ptr p = malloc(sizeof(struct node));
    p->val = x;
    if(s)
    {
        printf("input value is %d\r\n", p->val);
    }
    p->next = s->next;
    s->next = p;
    return;
}

int pop(stack s)
{
    if(!s)
    {
        printf("there is no stuffs in the stack\r\n");
        return 0;
    }
    ptr p = s->next;
    s->next = s->next->next;
    int tmp = p->val;
    free(p);
    return tmp;
}

int top(stack s)
{
    if(!s)
    {
        printf("there is no stuffs in the stack\r\n");
        return 0;
    }
    ptr p = s->next;
    int tmp = p->val;
    return tmp;
}

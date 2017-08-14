/*demo of linked list written without assistance*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node *ptr;

typedef ptr list;

struct node
{
    int val;
    ptr next;
};

list createlist(void);

void show_list(list l);

int islast(ptr p, list l);

ptr find(int x, list l);

ptr findprevious(int x, list l);

void delete(int x, list l);

void insert(int x, ptr p);

ptr revert(list l, int m, int n);

void main(void)
{
    ptr head;
    
    head = createlist();
    
    show_list(head);

    ptr p;
   
    printf("123123\r\n");
    
    p = find(5, head);

    printf("is 5 the ast element? %d \r\n", islast(p, head));

    printf("delete 5\r\n");

    delete(5, head);

    show_list(head);

    printf("find previous\r\n");

    p = findprevious(3, head);

    printf("insert 6\r\n");

    insert(6, p);

    show_list(head);

    printf("try with revert\r\n");

    revert(head, 2, 4);

    show_list(head);
    
    return;
}

list createlist(void)
{
    ptr head = malloc(sizeof(struct node));

    ptr p1;

    int tmp  = 1;
    
    for(int i = 0; i < 5; i++)
    {
        ptr tmpcell;
        
        tmpcell=malloc(sizeof(struct node));
        
        printf("\r\nplease input the %dth item >> \r\n", i);
       
        fflush(stdout);

        scanf("%d", &tmp);
        
        tmpcell->val = tmp;

        tmpcell->next = NULL;
        
        if(i == 0)
        {
            head->next = tmpcell;
            p1 = tmpcell;
        }
        else
        {
            p1->next = tmpcell;
            p1 = tmpcell;
        }        
    }

    return head; 

}


void show_list(list l)
{
    ptr p1 = l->next;
    
    int cnt = 0;
    
    while(p1!=NULL) 
    {
        printf("the %d th item is  %d \r\n", cnt, p1->val);
        p1 = p1->next;
        cnt++;
    
    }
    return;
}


int islast(ptr p, list l)
{
    if(!p)
        return 0;
    return p->next == NULL;
}

ptr find(int x, list l)
{
    ptr p;
    p = l->next;
    printf("in find function and x is %d \r\n", x);
    while(p && p->val!=x)
    {
        printf("p->val is %d \r\n", p->val);
        p = p->next;
    }
    return p;
}

ptr findprevious(int x, list l)
{
    ptr p;
    p = l;
    
    while(p->next && p->next->val!=x)
        p = p->next;
    
    return p;

}

void delete(int x, list l)
{
    ptr p;
    
    p = findprevious(x, l);

    if(!islast(p, l))
    {
        ptr tmp = p->next;
        p->next = p->next->next;
        free(tmp);
    }   
    return;
}

void insert(int x, ptr p)
{
    if(!p)
    {
        printf("NULL Pointer\r\n");
    }
    
    ptr tmp = malloc(sizeof(struct node));
    
    tmp->val = x;
    
    tmp->next = p->next;
    
    p->next = tmp;
    
    return;
}

ptr revert(list l, int m, int n)
{
    if(m == n)
    {
        return l;
    }
    ptr pre, cur = l, front = NULL, last;
    
    int i = 1;
    
    for(; i< m; i++)
    {
        cur = cur->next;
    }
    
    pre = cur;
    
    last = cur->next;
    
    for(; i <= n; i++)
    {
        cur = pre->next;
        pre->next = cur->next;
        cur->next = front;
        front = cur;
    }
    
    last->next = pre->next;
    
    pre->next = front;

    return l;
}

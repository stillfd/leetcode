/*demo code for understanding the bst!!!*/
#include<stdlib.h>
#include<stdio.h>

// struct annoucement
typedef struct TreeNode* ptr;

typedef ptr bst;

struct TreeNode
{
    int val;
    ptr left;
    ptr right;
};


// annocement of the sub functions

void initialize(bst* T);

bst makeempty(bst T);

ptr find(int x, bst T);

ptr findmin(bst T);

ptr findmax(bst T);

bst insert(int x, bst T);

bst delete(int x, bst T);

int retrive(ptr p);

int depth(ptr p);

void print_node_at_level(bst T, int level);

void show(bst T);

// main function
void main(void)
{
    bst T;

    initialize(&T);
   
    printf("Here comes the display of the tree with level travesal\r\n");
    
    show(T);

    printf("here comes demo of find min and find max\r\n");

    ptr p = findmin(T);

    printf("min >> %d \r\n", p->val);

    p = findmax(T);

    printf("max >> %d \r\n", p->val);

    printf("here comes test of element find function\r\n");

    p = find(5, T);

    printf("the node find contains value >> %d\r\n", p->val);

    printf("make empty of the tree\r\n");

    makeempty(T);
    return;
}

bst makeempty(bst T)
{
    if(T)
    {
        makeempty(T->left);
        makeempty(T->right);
        free(T);
    }
    return NULL;
}

ptr find(int x, bst T)
{
    if (!T)
        return NULL;
    if(x < T->val)
    {
        return find(x, T->left);
    }
    if(x > T->val)
    {
        return find(x, T->right);
    }
    return T;
}

ptr findmin(bst T)
{
    if(!T)
    {
        return NULL;
    }
    if(!T->left)
    {
        return T;
    }
    return findmin(T->left);
}

ptr findmax(bst T)
{
    if(!T)
        return NULL;
    while(T->right)
        T = T->right;
    return T;
}
// details of realization

void print_node_at_level(bst T, int level)
{

    if(!T || level < 1)
    {
        return;
    }
    if(level == 1)
    {
        printf("%d ", T->val);
        return;
    }

    print_node_at_level(T->left, level - 1);

    print_node_at_level(T->right, level - 1);
    
    return;

}


void show(bst T)
{
    if(!T)
    {
        return;
    }

    int d = depth(T);
    
    int i = 1;

    for(; i<= d; i++)
    {
        print_node_at_level(T,i);
        printf("\r\n");
    }

    return;
}

int depth(ptr p)
{
    if(!p)
    {
        return 0;
    }
   
    printf("p->val\r\n", p->val);
    
    int l = depth(p->left);
    
    int r = depth(p->right);
   
    return 1 + (l>r?l:r);
}


void initialize(bst* T)
{

    int tmp;

    printf("\r\n pls input data for current node\r\n");

    fflush(stdout);

    scanf("%d", &tmp);
    
    if(0 == tmp)
    {
        *T = NULL;
    }
    else
    {
        *T = (ptr)malloc(sizeof(struct TreeNode));
        (*T)->val = tmp;
        initialize(&((*T)->left));
        initialize(&((*T)->right));
    }
    return;
}

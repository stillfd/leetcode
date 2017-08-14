/*used for bst template*/

#include<iostream>
#include<string>

using namespace std;

typedef struct node* ptr;
typedef ptr Tree;

struct node
{
    int val;
    struct node* left;
    struct node* right;
};

void init(Tree *T);
int depth(Tree T);
void show(Tree T);
void prtnode(Tree T, int x);

int main(void)
{
    Tree T;
    init(&T);
    cout<<"here gives the level traversal of the bst"<<endl;
    show(T);
    return 1;
}

void show(Tree T)
{
	int d = depth(T);
	for(int i = 1; i <= d; i++)
	{
		prtnode(T, i);
		cout<<endl;
	}
	return;
}

void prtnode(Tree T, int x)
{
	if( !T || x <= 0 )
		return;
	if(x == 1)
	{
		cout<<T->val<<" ";
	}
	else
	{
		prtnode(T->left, x-1);
		prtnode(T->right, x-1);
	}
	return;
}

int depth(Tree T)
{
	if(!T)
		return 0;
	int l = depth(T->left);
	int r = depth(T->right);
	return (1 + (l > r ? l : r));
}

// create the bst tree by preorder traversal;
void init(Tree *T)
{
	int a;
    cout<<"please enter the value of current node"<<endl;
    cin>>a;
    if(0 == a)
	{
		*T = NULL;
	}
    else
    {
    	*T = new struct node;
    	(*T)->val = a;
    	init(&((*T)->left));
		init(&((*T)->right));
    }
    return;
}

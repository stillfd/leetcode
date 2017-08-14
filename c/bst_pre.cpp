/*used for bst template*/

#include<iostream>
#include<string>
#include<stack>

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
void preorder_recursive(Tree T);
void preorder_dfs(Tree T);

int main(void)
{
    Tree T;
    init(&T);
    cout<<"here gives the level traversal of the bst"<<endl;
    show(T);
    cout<<"here is the preorder_dfs"<<endl;
    preorder_recursive(T);
    cout<<endl;
    cout<<"here is non-recursive preorder dfs"<<endl;
    preorder_dfs(T);
    return 1;
}

void preorder_dfs(Tree T)
{
    if(!T)
        return;
    stack<ptr> s;
    while(T || s.size())
    {
        while(T)
        {         
            cout<<T->val<<endl;
            s.push(T);
            T = T->left;
        }
        ptr p = s.top();
        s.pop();
        T = p->right;
    }

    return;
}

void preorder_recursive(Tree T)
{
    if(!T)
        return;
    cout<<T->val;
    preorder_recursive(T->left);
    preorder_recursive(T->right);
    return;
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

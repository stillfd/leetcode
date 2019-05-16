#include<stdlib.h>
#include<stdio.h>
#include<stack>
using namespace std;
typedef struct BiTNode{
	char val;
	BiTNode* left;
	BiTNode* right;
}BiTNode, *BiTree;


void create(BiTree *T)
{
	char ch;
	ch = getchar();
	if(ch == ' ')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTNode*)malloc(sizeof(BiTNode));
		(*T)->val = ch;
		create(&(*T)->left);
		create(&(*T)->right);
	}
	return;
}

void preOrder1(BiTree T)
{
	if(T)
	{
		printf("%c", T->val);
		preOrder1(T->left);
		preOrder1(T->right);
	}
}
void inOrder1(BiTree T)
{
	if(T)
	{
		inOrder1(T->left);
		printf("%c", T->val);
		inOrder1(T->right);
	}
}
void postOrder1(BiTree T)
{
	if(T)
	{
		
		postOrder1(T->left);
		postOrder1(T->right);
		printf("%c", T->val);
	}
}

void preOrder(BiTree T)
{
	BiTree p;
	p = T;
	stack<BiTree> s;
	while(1)
	{
		while(p)
		{
			printf("%c",p->val);
			s.push(p);
			p = p->left;
		}
		if(s.empty()) break;
		p = s.top();
		s.pop();
		p = p->right;
	}
}
void preOrder2(BiTree T)
{
	BiTree p;
	p = T;
	stack<BiTree> s;
	s.push(T);
	while(!s.empty())
	{
		p = s.top();s.pop();
		printf("%c",p->val);
		if(p->right) s.push(p->right);
		if(p->left) s.push(p->left);
	}
	return;
}
void inOrder(BiTree T)
{
	BiTree p;
	p = T;
	stack<BiTree> s;
	while(1)
	{
		while(p)
		{
			
			s.push(p);
			p = p->left;
		}
		if(s.empty()) break;
		p = s.top();
		printf("%c",p->val);
		s.pop();
		p = p->right;
	}
}

void postOrder(BiTree T)
{
	BiTree p, prev;
	p = T;
	prev = NULL;
	stack<BiTree> s;
	while(1)
	{
		while(p)
		{
			s.push(p);
			p = p->left;
		}
		if(s.empty()) break;
		p = s.top();
		if(p->right != NULL && p->right!=prev)
		{
			p = p->right;
			prev = p;
		}
		else
		{
			prev = p;
			printf("%c",p->val);
			s.pop();	
			p = NULL;
		}
	}
}

int main()
{
	BiTree T = NULL;
	create(&T);
	printf("Display BST, preorder, recursive\n");
	preOrder1(T); 
	printf("\n");
	printf("Display BST, inorder, recursive\n");
	inOrder1(T);
	printf("\n");
	printf("Display BST, postorder, recursive\n");
	postOrder1(T);	
	printf("\n");
	printf("Display BST, preorder, iterative\n");
	preOrder(T);
	printf("\n");
	printf("Display BST, preorder2, iterative\n");
	preOrder2(T);
	printf("\n");
	printf("Display BST, inorder, iterative\n");
	inOrder(T);
	printf("\n");
	printf("Display BST, postorder, iterative\n");
	postOrder(T);
	printf("\n");
	return 0;
}

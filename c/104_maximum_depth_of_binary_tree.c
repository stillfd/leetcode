#include<stdio.h>

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int maxDepth(struct TreeNode* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return (l > r) ? l : r + 1;
    }
}

void main(void)
{
    struct TreeNode* a = NULL;
    int l = maxDepth(a);
    printf("%d");
    return;
}

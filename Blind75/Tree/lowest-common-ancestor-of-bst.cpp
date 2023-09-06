#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void printTree(TreeNode *root)
{
    if (root != nullptr)
    {
        cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
    }
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    TreeNode *cur = root;
    while (cur != nullptr)
    {
        if (p->val > cur->val && q->val > cur->val)
        {
            cur = cur->right;
        }
        else if (p->val < cur->val && q->val < cur->val)
        {
            cur = cur->left;
        }
        else
            return cur;
    }
    return cur;
}

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    TreeNode *temp = root->left;
    temp->left = new TreeNode(1);
    temp->right = new TreeNode(3);
    temp = root->right;
    temp->left = new TreeNode(6);
    temp->right = new TreeNode(9);
    cout << lowestCommonAncestor(root, temp->left, temp->right)->val;
    return 0;
}

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
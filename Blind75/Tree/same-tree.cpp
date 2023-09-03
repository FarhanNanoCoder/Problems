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

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if ((p != nullptr && q == nullptr) || (p == nullptr && q != nullptr))
        return false;
    else if (p == nullptr && q == nullptr)
        return true;
    else if (p->val != q->val)
        return false;
    else
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}

int main(){
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    TreeNode *temp = root->left;
    temp->left = new TreeNode(1);
    temp->right = new TreeNode(3);
    temp = root->right;
    temp->left = new TreeNode(6);
    temp->right = new TreeNode(9);
    TreeNode *root2 = new TreeNode(4);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(7);
    temp = root2->left;
    temp->left = new TreeNode(1);
    temp->right = new TreeNode(3);
    temp = root2->right;
    temp->left = new TreeNode(6);
    temp->right = new TreeNode(9);
    cout << isSameTree(root, root2);
    return 0;
}

// https://leetcode.com/problems/same-tree/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

void traverse(TreeNode *root, int &sum)
{
    if (root)
    {
        traverse(root->right, sum);
        sum += root->val;
        root->val = sum;
        traverse(root->left, sum);
    }
}
TreeNode *bstToGst(TreeNode *root)
{
    int sum = 0;
    traverse(root, sum);
    return root;
}

int main(){
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(6);
    root->right->right->right = new TreeNode(8);
    TreeNode *res = bstToGst(root);
    return 0;
}

//https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
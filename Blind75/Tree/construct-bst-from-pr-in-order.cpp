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
    else
    {
        cout << "null ";
    }
}

TreeNode *build(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd)
{
    if (preStart > preEnd || inStart > inEnd)
        return nullptr;
    TreeNode *root = new TreeNode(preorder[preStart]);
    int inRoot = 0;
    for (int i = inStart; i <= inEnd; i++)
    {
        if (inorder[i] == root->val)
        {
            inRoot = i;
            break;
        }
    }
    int numsLeft = inRoot - inStart;
    root->left = build(preorder, inorder, preStart + 1, preStart + numsLeft, inStart, inRoot - 1);
    root->right = build(preorder, inorder, preStart + numsLeft + 1, preEnd, inRoot + 1, inEnd);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *root = buildTree(preorder, inorder);
    printTree(root);
    return 0;
}

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
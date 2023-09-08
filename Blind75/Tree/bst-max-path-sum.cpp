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

int dfs(TreeNode *root, int &maxSum)
{
    if (root == nullptr)
        return 0;
    int left = max(dfs(root->left, maxSum), 0);
    int right = max(dfs(root->right, maxSum), 0);

    int currPath = root->val + left + right;
    maxSum = max(currPath, maxSum);
    return root->val + max(left, right);
}

int maxPathSum(TreeNode *root)
{
    int maxSum = -999999999;
    dfs(root, maxSum);
    return maxSum;
}
int main(){
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(15);
    cout << maxPathSum(root);
    return 0;
}

// https://leetcode.com/problems/binary-tree-maximum-path-sum/
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

vector<int> nums;

void inOrderTraverse(TreeNode *root)
{
    if (root == nullptr)
        return;
    inOrderTraverse(root->left);
    nums.push_back(root->val);
    inOrderTraverse(root->right);
}
TreeNode *buildBalanceBST(int l, int r)
{
    if (!(l <= r))
        return nullptr;
    int m = (l + r) / 2;
    TreeNode *node = new TreeNode(nums[m]);
    node->left = buildBalanceBST(l, m - 1);
    node->right = buildBalanceBST(m + 1, r);
    return node;
}
TreeNode *balanceBST(TreeNode *root)
{
    inOrderTraverse(root);
    cout << nums.size() << endl;
    // return root;
    return buildBalanceBST(0, nums.size() - 1);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(11);
    root->right->left->left = new TreeNode(12);
    root->right->left->right = new TreeNode(13);
    root->right->right->left = new TreeNode(14);
    root->right->right->right = new TreeNode(15);
    TreeNode *newRoot = balanceBST(root);
}

// https://leetcode.com/problems/balance-a-binary-search-tree/
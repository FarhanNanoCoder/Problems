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

bool valid(long long int l, TreeNode *node, long long int r)
{
    if (node == nullptr)
        return true;
    else if (l >= node->val || r <= node->val)
        return false;
    else
        return (valid(l, node->left, node->val) && valid(node->val, node->right, r));
}
bool isValidBST(TreeNode *root)
{
    return valid(-99999999999999, root, 99999999999999);
}

int main(){
    TreeNode *root = new TreeNode(2147483647);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(7);
    // TreeNode *temp = root->left;
    // temp->left = new TreeNode(1);
    // temp->right = new TreeNode(3);
    // temp = root->right;
    // temp->left = new TreeNode(6);
    // temp->right = new TreeNode(9);
    cout << isValidBST(root);
    return 0;
}

// https://leetcode.com/problems/validate-binary-search-tree/
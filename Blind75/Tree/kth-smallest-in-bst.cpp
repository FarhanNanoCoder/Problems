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

int kthSmallest(TreeNode *root, int k)
{
    stack<TreeNode *> s;
    TreeNode *curr = root;
    while (curr != nullptr || !s.empty())
    {
        while (curr != nullptr)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        k--;
        if (k == 0)
            return curr->val;
        curr = curr->right;
    }
    return -1;
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    TreeNode *temp = root->left;
    temp->left = new TreeNode(2);
    temp->right = new TreeNode(4);
    temp = root->right;
    temp->right = new TreeNode(7);
    cout << kthSmallest(root, 3);

    return 0;
}

// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
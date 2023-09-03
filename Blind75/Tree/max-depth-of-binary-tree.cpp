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

int maxDepth(TreeNode *root)
{
    // DFS

    if (root == nullptr)
        return 0;
    else
        return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));

    // BFS
    // deque<TreeNode *> q;
    // int level = 0;
    // q.push_back(root);
    // while (!q.empty())
    // {
    //     int len = q.size();
    //     for (auto it = q.begin(); len--; it++)
    //     {
    //         if ((*it)->left != nullptr)
    //             q.push_back((*it)->left);
    //         if ((*it)->right != nullptr)
    //             q.push_back((*it)->right);

    //         q.pop_front();
    //     }
    //     level++;
    // }
    // return level;
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
    cout << maxDepth(root);
    return 0;
}

// https: //leetcode.com/problems/maximum-depth-of-binary-tree/
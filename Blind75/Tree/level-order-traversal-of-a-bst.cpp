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

void printVectorOfVectors(vector<vector<int>> res)
{
    for (auto it = res.begin(); it != res.end(); it++)
    {
        for (auto it2 = (*it).begin(); it2 != (*it).end(); it2++)
        {
            cout << *it2 << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    if (root == nullptr)
        return res;
    else
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int len = q.size();
            vector<int> temp;
            for (int i = 0; i < len; i++)
            {
                TreeNode *t = q.front();
                if (t->left != nullptr)
                    q.push(t->left);
                if (t->right != nullptr)
                    q.push(t->right);
                temp.push_back(t->val);
                q.pop();
            }
            res.push_back(temp);
        }
    }
    return res;
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
    vector<vector<int>> res = levelOrder(root);
    for (auto it = res.begin(); it != res.end(); it++)
    {
        for (auto it2 = (*it).begin(); it2 != (*it).end(); it2++)
        {
            cout << *it2 << " ";
        }
        cout << endl;
    }
    return 0;
}

// https://leetcode.com/problems/maximum-depth-of-binary-tree/
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

void encode(TreeNode *root, ostringstream &out)
{
    if (root == nullptr)
    {
        out << "N ";
        return;
    }
    out << root->val << " ";
    encode(root->left, out);
    encode(root->right, out);
}

TreeNode *decode(istringstream &in)
{
    string val = "";
    in >> val;
    if (val == "N")
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(stoi(val));
    root->left = decode(in);
    root->right = decode(in);
    return root;
}

string serialize(TreeNode *root)
{
    ostringstream out;
    encode(root, out);
    return out.str();
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    istringstream in(data);
    return decode(in);
}

int main(){
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(15);
    cout << serialize(root) << endl;
    TreeNode *root2 = deserialize(serialize(root));
    printTree(root2);
    return 0;
}

// https://leetcode.com/problems/serialize-and-deserialize-bst/
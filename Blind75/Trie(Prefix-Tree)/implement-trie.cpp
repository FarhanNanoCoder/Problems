#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    bool end = false;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};

void printTrieNode(TrieNode *root)
{
    for (int i = 0; i < 26; i++)
    {
        if (root->children[i] != nullptr)
        {
            cout << char(i + 'a') << " ";
            printTrieNode(root->children[i]);
        }
    }
    cout << endl;
}

class Trie
{

public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (curr->children[word[i] - 'a'] == nullptr)
                curr->children[word[i] - 'a'] = new TrieNode();
            curr = curr->children[word[i] - 'a'];
        }
        curr->end = true;
    }

    bool search(string word)
    {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (curr->children[word[i] - 'a'] != nullptr)
                curr = curr->children[word[i] - 'a'];
            else
                return false;
        }
        return curr->end;
    }

    bool startsWith(string prefix)
    {
        TrieNode *curr = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (curr->children[prefix[i] - 'a'] != nullptr)
                curr = curr->children[prefix[i] - 'a'];
            else
                return false;
        }
        return true;
    }
};
int main()
{
    Trie *obj = new Trie();
    obj->insert("apple");
    cout << obj->search("apple") << endl;
    cout << obj->startsWith("app") << endl;
    cout << obj->search("app") << endl;
    return 0;
}

// https://leetcode.com/problems/implement-trie-prefix-tree/
#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    // map<char, TrieNode *> children;
    bool end;

    TrieNode()
    {
        end = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }
    int getIndexOfCharacter(char c)
    {
        if ('a' <= c && c <= 'z')
            return (c - 'a' + 26);
        return (c - 'a' + 32);
    }

    void insert(string word)
    {
        TrieNode *ptr = root;
        for (int i = 0; i < word.size(); i++)
        {
            // int j = getIndexOfCharacter(word[i]);
            if (ptr->children[word[i]] == nullptr)
                ptr->children[word[i]] = new TrieNode();
            ptr = ptr->children[word[i]];
        }
        ptr->end = true;
        cout << "inserted" << endl;
    }

    bool search(string word)
    {
        TrieNode *ptr = root;
        for (int i = 0; i < word.size(); i++)
        {
            // int j = getIndexOfCharacter(word[i]);
            if (ptr->children[word[i]] == nullptr)
                return false;
            ptr = ptr->children[word[i]];
        }
        return ptr->end;
    }

    bool startsWith(string word)
    {
        TrieNode *ptr = root;
        for (int i = 0; i < word.size(); i++)
        {
            // int j = getIndexOfCharacter(word[i]);
            if (ptr->children[word[i]] == nullptr)
                return false;
            ptr = ptr->children[word[i]];
        }
        return true;
    }

    void collectStrings(TrieNode *ptr, string str, vector<string> &res)
    {
        if (ptr->end)
            res.push_back(str);
        if (ptr->children.size() == 0)
            return;

        for (auto it : ptr->children)
        {
            collectStrings(it.second, str + it.first, res);
        }
    }

    vector<string> matchesPrefix(string prefix)
    {
        TrieNode *ptr = root;
        vector<string> res;
        string str = "";
        for (int i = 0; i < prefix.size(); i++)
        {
            // int j = getIndexOfCharacter(prefix[i]);
            if (ptr->children[prefix[i]] == nullptr)
            {
                cout << "not matched" << endl;
                return res;
            }
            str += prefix[i];

            ptr = ptr->children[prefix[i]];
        }
        // collect strings
        collectStrings(ptr, str, res);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << endl;

        return res;
    }
};

int main()
{
    Trie db = Trie();
    db.insert("hello");
    db.insert("app");
    db.insert("apple");
    db.insert("apdle");
    db.insert("applicable");
    db.insert("Apply");
    db.matchesPrefix("a");
    // cout << db.search("helo") << endl;
    // cout << db.startsWith("ap") << endl;
}
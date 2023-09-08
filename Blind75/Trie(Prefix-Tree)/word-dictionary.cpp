#include <bits/stdc++.h>
using namespace std;

class WordNode
{
public:
    WordNode *children[26];
    bool end = false;
    WordNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};

void printWordNode(WordNode *root)
{
    for (int i = 0; i < 26; i++)
    {
        if (root->children[i] != nullptr)
        {
            cout << char(i + 'a') << " ";
            printWordNode(root->children[i]);
        }
    }
    cout << endl;
}
class WordDictionary
{
public:
    WordNode *root;
    WordDictionary()
    {
        root = new WordNode();
    }

    void addWord(string word)
    {
        WordNode *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (curr->children[word[i] - 'a'] == nullptr)
                curr->children[word[i] - 'a'] = new WordNode();
            curr = curr->children[word[i] - 'a'];
        }
        curr->end = true;
    }

    bool searchInNode(string &word, int i, WordNode *node)
    {
        if (node == nullptr)
            return false;
        if (i == word.size())
            return node->end;
        if (word[i] != '.')
        {
            return searchInNode(word, i + 1, node->children[word[i] - 'a']);
        }
        for (int j = 0; j < 26; j++)
        {
            if (searchInNode(word, i + 1, node->children[j]))
                return true;
        }
        return false;
    }

    bool search(string word)
    {
        WordNode *curr = root;
        return searchInNode(word, 0, curr);
    }
};

int main()
{
    WordDictionary *obj = new WordDictionary();
    obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");
    cout << obj->search("pad") << endl;
    cout << obj->search("bad") << endl;
    cout << obj->search(".ad") << endl;
    cout << obj->search("b..") << endl;
    return 0;
}

// https://leetcode.com/problems/add-and-search-word-data-structure-design/
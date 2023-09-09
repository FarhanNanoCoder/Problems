#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    bool isWord;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isWord = false;
    }
};

class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        for (int i = 0; i < words.size(); i++)
        {
            insert(words[i]);
        }

        int m = board.size();
        int n = board[0].size();

        TrieNode *node = root;
        vector<string> result;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                search(board, i, j, m, n, node, "", result);
            }
        }

        return result;
    }

private:
    TrieNode *root = new TrieNode();

    void insert(string word)
    {
        TrieNode *node = root;
        int curr = 0;

        for (int i = 0; i < word.size(); i++)
        {
            curr = word[i] - 'a';
            if (node->children[curr] == NULL)
            {
                node->children[curr] = new TrieNode();
            }
            node = node->children[curr];
        }

        node->isWord = true;
    }

    void search(vector<vector<char>> &board, int i, int j, int m, int n, TrieNode *node, string word, vector<string> &result)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '0')
            return;

        if (node->children[board[i][j] - 'a'] == NULL)
            return;

        node = node->children[board[i][j] - 'a'];
        word += board[i][j];

        if (node->isWord)
        {
            result.push_back(word);
            node->isWord = false;
        }

        char temp = board[i][j];
        board[i][j] = '0';

        search(board, i + 1, j, m, n, node, word, result);
        search(board, i - 1, j, m, n, node, word, result);
        search(board, i, j + 1, m, n, node, word, result);
        search(board, i, j - 1, m, n, node, word, result);

        board[i][j] = temp;
    }
};

int main()
{
    vector<vector<char>> board = {{'o', 'a', 'a', 'n'},
                                  {'e', 't', 'a', 'e'},
                                  {'i', 'h', 'k', 'r'},
                                  {'i', 'f', 'l', 'v'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};
    Solution s;
    vector<string> result = s.findWords(board, words);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}

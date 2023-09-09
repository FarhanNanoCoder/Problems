#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>> &board, string &word, vector<vector<bool>> &path, int r, int c, int i)
{
    if (i == word.size())
        return true;
    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || path[r][c] || board[r][c] != word[i])
        return false;
    path[r][c] = true;
    bool res = dfs(board, word, path, r + 1, c, i + 1) || dfs(board, word, path, r - 1, c, i + 1) || dfs(board, word, path, r, c + 1, i + 1) || dfs(board, word, path, r, c - 1, i + 1);
    path[r][c] = false;
    return res;
}

bool exist(vector<vector<char>> &board, string word)
{
    int COL = board[0].size();
    int ROW = board.size();
    vector<vector<bool>> path(ROW, vector<bool>(COL, false));
    for (int r = 0; r < ROW; r++)
    {
        for (int c = 0; c < COL; c++)
        {
            if (dfs(board, word, path, r, c, 0))
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    cout << exist(board, word) << endl;
    return 0;
}

// https://leetcode.com/problems/word-search/
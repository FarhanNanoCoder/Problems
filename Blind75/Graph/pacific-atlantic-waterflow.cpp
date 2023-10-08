#include <bits/stdc++.h>
using namespace std;

void dfs(int r, int c, vector<vector<bool>> &visited, vector<vector<int>> &heights, int prevHeight)
{
    if (r < 0 || c < 0 || r >= heights.size() || c >= heights[0].size() || visited[r][c] || heights[r][c] < prevHeight)
        return;
    visited[r][c] = true;

    dfs(r + 1, c, visited, heights, heights[r][c]);
    dfs(r - 1, c, visited, heights, heights[r][c]);
    dfs(r, c + 1, visited, heights, heights[r][c]);
    dfs(r, c - 1, visited, heights, heights[r][c]);
}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    if (heights.empty())
        return {{}};
    int ROW = heights.size(), COL = heights[0].size();
    vector<vector<bool>> pac(heights.size(), vector<bool>(heights[0].size(), false)), alt(heights.size(), vector<bool>(heights[0].size(), false));

    // FIRST & LAST ROW
    for (int i = 0; i < COL; i++)
    {
        dfs(0, i, pac, heights, heights[0][i]);
        dfs(ROW - 1, i, alt, heights, heights[ROW - 1][i]);
    }
    // FIRST AND LAST COL
    for (int i = 0; i < ROW; i++)
    {
        dfs(i, 0, pac, heights, heights[i][0]);
        dfs(i, COL - 1, alt, heights, heights[i][COL - 1]);
    }

    vector<vector<int>> res;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (pac[i][j] && alt[i][j])
                res.push_back({i, j});
        }
    }
    return res;
}
int main()
{
    vector<vector<int>> heights = {{1, 2, 2, 3, 5},
                                   {3, 2, 3, 4, 4},
                                   {2, 4, 5, 3, 1},
                                   {6, 7, 1, 4, 5},
                                   {5, 1, 1, 2, 4}};
    vector<vector<int>> res = pacificAtlantic(heights);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i][0] << ", " << res[i][1] << endl;
    }
    return 0;
}

// https://leetcode.com/problems/pacific-atlantic-water-flow/

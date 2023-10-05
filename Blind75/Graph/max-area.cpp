#include <bits/stdc++.h>
using namespace std;

void dfs(int r, int c, vector<vector<bool>> &visited, vector<vector<int>> &grid, int ROW, int COL, int &area)
{
    if (r >= ROW || c >= COL || r < 0 || c < 0 || visited[r][c] || grid[r][c] == 0)
        return;
    area++;
    visited[r][c] = true;
    dfs(r + 1, c, visited, grid, ROW, COL, area);
    dfs(r - 1, c, visited, grid, ROW, COL, area);
    dfs(r, c + 1, visited, grid, ROW, COL, area);
    dfs(r, c - 1, visited, grid, ROW, COL, area);
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    if (grid.empty())
        return 0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    int area = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (!visited[i][j] && grid[i][j] == 1)
            {
                int temp = 0;
                dfs(i, j, visited, grid, grid.size(), grid[i].size(), temp);
                area = max(area, temp);
            }
        }
    }
    return area;
}
int main()
{
    vector<vector<int>> grid = {{1, 1, 0, 0, 0},
                                {1, 1, 0, 1, 0},
                                {0, 0, 0, 1, 1},
                                {0, 1, 0, 1, 1}};
    cout << maxAreaOfIsland(grid) << endl;
    return 0;
}

// https://leetcode.com/problems/max-area-of-island/
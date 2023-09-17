#include <bits/stdc++.h>
using namespace std;

void bfs(int r, int c, vector<vector<bool>> &visited, vector<pair<int, int>> &directions, vector<vector<char>> &grid, int ROW, int COL)
{
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;
    while (!q.empty())
    {
        pair<int, int> vertex = q.front();
        for (int i = 0; i < directions.size(); i++)
        {
            r = vertex.first + directions[i].first;
            c = vertex.second + directions[i].second;
            if (r >= 0 && r < ROW && c >= 0 && c < COL && !visited[r][c] && grid[r][c] == '1')
            {
                q.push({r, c});
                visited[r][c] = true;
            }
        }
        q.pop();
    }
}

int numIslands(vector<vector<char>> &grid)
{
    if (grid.empty())
        return 0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    vector<pair<int, int>>
        directions = {{1, 0},
                      {-1, 0},
                      {0, 1},
                      {0, -1}};
    int islands = 0;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (!visited[i][j] && grid[i][j] == '1')
            {
                bfs(i, j, visited, directions, grid, grid.size(), grid[i].size());
                islands++;
            }
        }
    }
    return islands;
}
int main()
{
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
                                 {'1', '1', '0', '1', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '0', '0', '0'}};
    cout << numIslands(grid) << endl;
    return 0;
}

// https://leetcode.com/problems/number-of-islands/

#include <bits/stdc++.h>
using namespace std;

bool dfs(int i, vector<bool> &visited, map<int, vector<int>> &adjacent, vector<bool> &canDone)
{
    if (i < 0 || i >= visited.size() || visited[i])
        return false;
    if (canDone[i] || adjacent[i].size() == 0)
        return true;
    visited[i] = true;
    for (int j = 0; j < adjacent[i].size(); j++)
    {
        if (!dfs(adjacent[i][j], visited, adjacent, canDone))
        {
            canDone[i] = false;
            visited[i] = false;
            return false;
        }
    }
    canDone[i] = true;
    visited[i] = false;
    return true;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    map<int, vector<int>> adjacent;
    vector<bool> canDone(numCourses, false);
    vector<bool> visited(numCourses, false);
    for (int i = 0; i < prerequisites.size(); i++)
    {
        if (adjacent.find(prerequisites[i][0]) != adjacent.end())
        {
            adjacent[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        else
        {
            adjacent[prerequisites[i][0]] = {prerequisites[i][1]};
        }
    }

    for (int i = 0; i < numCourses; i++)
    {
        if (!dfs(i, visited, adjacent, canDone))
            return false;
    }
    return true;
}
int main()
{
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    cout << canFinish(numCourses, prerequisites) << endl;
    return 0;
}

// https://leetcode.com/problems/course-schedule/

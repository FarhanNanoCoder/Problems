    vector<vector<int>> history;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            history[i][j] = -1;
        }
    }
    c = countPaths(0, 0, m, n, history);
    printVectorOfVectors(history);
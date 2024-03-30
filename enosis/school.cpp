#include <bits/stdc++.h>
using namespace std;

int invigilatorCount(int k, vector<pair<int, int>> &students, vector<pair<int, int>> &q)
{
    int a[100000] = {};
    int b[100000] = {};
    vector<int> res;
    for (int i = 0; i < students.size(); i++)
    {
        a[students[i].first]++;
        a[students[i].second+1]--;
        // cout<<a[students[i].first]<<" "<<a[students[i].second]<<endl;
    }
   

    int last = 1;
    int c = 0;
    for (int i = 0; i < q.size(); i++)
    {
        for (int j = last; j <= q[i].second; j++)
        {
            a[j] += a[j - 1];
            // cout<<a[j]<<" ";

        }
        cout<<endl;
        for (int j = last; j <= q[i].second; j++)
        {
            if (a[j] >= k) b[j]=b[j-1]+1;
            else b[j]=b[j-1];
                
            // cout<<b[j]<<" ";
        }
        cout<<endl;
        last = q[i].second + 1;

        c += b[q[i].second] - b[q[i].first - 1];
        res.push_back(b[q[i].second] - b[q[i].first - 1]);
        cout << b[q[i].second] - b[q[i].first - 1] << endl;
    }
    return c;
}

int main()
{
    int k = 2;
    vector<pair<int, int>> students = {{2, 9}, {3, 5}, {7, 8}};
    vector<pair<int, int>> q = {{1, 4}, {6, 7}};
    int res = invigilatorCount(k, students, q);
    // cout << res << endl;    
    return 0;
}

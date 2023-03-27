#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
void printVectorOfVectors(vector<vector<int>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        printVector(v[i]);
        cout << endl;
    }
    cout << endl;
}
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> res;
    res.push_back({1});
    if (numRows == 1)
    {
        return res;
    }
    res.push_back({1, 1});
    if (numRows == 2)
    {
        return res;
    }
    vector<int> temp;
    for (int i = 2; i < numRows; i++)
    {

        temp.push_back(1);
        for (int j = 1; j < i; j++)
        {
            temp.push_back(res[i - 1][j - 1] + res[i - 1][j]);
        }
        temp.push_back(1);
        res.push_back(temp);
        temp.clear();
    }
       // printVectorOfVectors(res);
    return res;
 
}
int main()
{
    generate(5);
}
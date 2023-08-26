#include <bits/stdc++.h>
using namespace std;

void printVectorOfMaps(vector<map<char, int>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (auto it = v[i].begin(); it != v[i].end(); it++)
        {
            cout << it->first << " " << it->second << endl;
        }
        cout << endl;
    }
    cout << endl;
}

void printVectorofVectorOfString(vector<vector<string>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<string>> groupAnagrams(vector<string> &strs)
{

    vector<map<char, int>> freq;

    vector<bool> included;
    // counting character frequencies
    for (int i = 0; i < strs.size(); i++)
    {
        map<char, int> temp;
        included.push_back(false);
        for (int j = 0; j < strs[i].size(); j++)
        {
            temp[strs[i][j]]++;
        }
        freq.push_back(temp);
        temp.clear();
    }
    vector<vector<string>> res;
    vector<string> temp;
    int c = 0;
    for (int i = 0; i < strs.size(); i++)
    {
        if (!included[i])
        {
            included[i] = true;

            for (int j = i+1; j < strs.size(); j++)
            {
                if (!included[j] && strs[i].size() == strs[j].size())
                {
                    bool flag = true;
                    for (auto it = freq[i].begin(); it != freq[i].end(); it++)
                    {
                        if (it->second != freq[j][it->first])
                        {
                            flag = false;
                            break;
                        };
                    }
                    if (flag)
                    {
                        included[j] = true;
                        temp.push_back(strs[j]);
                        // c++;
                    }
                }
            }
            temp.push_back(strs[i]);
            res.push_back(temp);
            temp.clear();
        }
    }
    // cout<<res.size();
    printVectorofVectorOfString(res);
    // printVectorOfMaps(freq);
}
int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    groupAnagrams(strs);
}

// https://leetcode.com/problems/group-anagrams/
#include <bits/stdc++.h>
using namespace std;
static bool comparator(pair<char, int> &a, pair<char, int> &b) { return a.second > b.second; }
string frequencySort(string s)
{
    map<char, int> freq;
    for (char c : s)
    {
        freq[c]++;
    }

    // Vector to store characters sorted by frequency
    vector<pair<char, int>> freqVec(freq.begin(), freq.end());

    // Sort the vector by frequency in descending order
    sort(freqVec.begin(), freqVec.end(), comparator);

    // Build the result string
    string result;
    for (auto &p : freqVec)
    {
        result.append(p.second, p.first);
    }

    return result;
}

int main()
{
    string s = "tree";
    cout << "Sorted string: " << frequencySort(s) << endl;
    return 0;
}

// https://leetcode.com/problems/sort-characters-by-frequency/description/
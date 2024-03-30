#include <bits/stdc++.h>
using namespace std;

void convertToLower(string &s)
{
    for (int i = 0; i < s.size(); i++)
        if ('A' <= s[i] && s[i] <= 'Z')
            s[i] += 32;
}

int rearrangeCount(vector<string> wordset, string sentence)
{
    // finding the anagram
    map<string, int> anagrams;
    for (int i = 0; i < wordset.size(); i++)
    {
        convertToLower(wordset[i]);
        sort(wordset[i].begin(), wordset[i].end());
        anagrams[wordset[i]]++;
    }
    int c = 1;
    string str = "";
    for (int i = 0; i < sentence.size(); i++)
    {
        if ('A' <= sentence[i] && sentence[i] <= 'Z')
            sentence[i] += 32;
        if ('a' <= sentence[i] && sentence[i] <= 'z')
            str += sentence[i];
        else if (sentence[i] == ' ')
        {
            if (!str.empty())
            {
                sort(str.begin(), str.end());
                if (anagrams.find(str) != anagrams.end())
                    c *= anagrams[str];
            }
            str = "";
        }
    }
    if (!str.empty())
    {
        sort(str.begin(), str.end());
        if (anagrams.find(str) != anagrams.end())
            c *= anagrams[str];
    }
    return c;
}

int main()
{
    vector<string> wordset = {"cat", "dog", "tac", "god", "act"};
    string sentence = "cat dog tac";
    cout << rearrangeCount(wordset, sentence) << endl;
    return 0;
}
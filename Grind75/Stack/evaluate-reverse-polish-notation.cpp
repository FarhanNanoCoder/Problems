#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string> &tokens)
{
    stack<int> nums;
    int t1, t2;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "*" || tokens[i] == "/" || tokens[i] == "+" || tokens[i] == "-")
        {
            t1 = nums.top();
            nums.pop();
            t2 = nums.top();
            nums.pop();
            if (tokens[i] == "*")
                nums.push(t2 * t1);
            else if (tokens[i] == "/")
                nums.push(t2 / t1);
            else if (tokens[i] == "+")
                nums.push(t2 + t1);
            else if (tokens[i] == "-")
                nums.push(t2 - t1);
        }
        else
        {
            nums.push(stoi(tokens[i]));
        }
    }
    return nums.top();
}
int main()
{
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << evalRPN(tokens) << endl;
    return 0;
}
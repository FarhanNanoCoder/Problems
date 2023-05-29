#include <bits/stdc++.h>
using namespace std;

string longDivision(string num, int divisor)
{
    string ans;
    int idx = 0;
    int temp = num[idx] - '0';

    while (temp < divisor)
    {
        temp = temp * 10 + (num[idx++] - '0');
    }
    while (idx < num.size())
    {
        ans += (temp / divisor) + '0';
        if (idx + 1 == num.size())
        {
            temp = (temp % divisor);
            break;
        }
        temp = (temp % divisor) * 10 + (num[++idx] - '0');
    }
    cout << "remainder: " << temp << endl;
    if (ans.length() == 0)
        return "0";
    return ans;
}

int main()
{
    cout << longDivision("47", 4);
}

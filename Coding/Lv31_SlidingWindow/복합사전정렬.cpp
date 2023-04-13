#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(string A, string B)
{
    if (A.length() == B.length())
        return A < B;
    else
        return A.length() < B.length();
}

int main()
{
    int n;
    vector<string> strs;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        strs.push_back(str);
    }

    sort(strs.begin(), strs.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        cout << strs[i] << '\n';
    }

    return 0;
}
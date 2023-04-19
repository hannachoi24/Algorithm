#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
    if (a.length() == b.length())
        return a < b;
    return a.length() < b.length();
}

int main()
{
    int n;
    cin >> n;

    vector<string> names(n);

    for (int i = 0; i < n; i++)
    {
        cin >> names[i];
    }

    sort(names.begin(), names.end(), cmp);

    for (string name : names)
    {
        cout << name << '\n';
    }

    return 0;
}
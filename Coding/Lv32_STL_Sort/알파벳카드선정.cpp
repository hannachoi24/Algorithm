#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    int n;

    cin >> s >> n;

    int dat[200] = {0};

    sort(s.begin(), s.end());

    int max = -99;
    char max_char;
    for (int i = s.length() - n; i < s.length(); i++)
    {
        dat[s[i]]++;

        if (dat[s[i]] > max)
        {
            max = dat[s[i]];
            max_char = s[i];
        }
    }

    cout << max_char;

    return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool Comp(string a, string b)
{
    if (a.length() != b.length())
    {
        return a.length() < b.length();
    }
    else
        return a < b;
}

int main()
{
    string words[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> words[i];
    }

    sort(words, words + 4, Comp);

    for (int i = 0; i < 4; ++i)
    {
        cout << words[i] << '\n';
    }

    return 0;
}
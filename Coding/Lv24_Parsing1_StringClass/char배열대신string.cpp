#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;

    int len = str.length();

    cout << str << '\n';

    for (int i = len - 1; i >= 0; i--)
    {
        cout << str[i];
    }

    return 0;
}
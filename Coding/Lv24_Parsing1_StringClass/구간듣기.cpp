#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;

    int a, b, c;
    cin >> a >> b >> c;
    string word = str.substr(a, b - a + 1);

    for (int i = 0; i < c; i++)
    {
        cout << word;
    }

    return 0;
}
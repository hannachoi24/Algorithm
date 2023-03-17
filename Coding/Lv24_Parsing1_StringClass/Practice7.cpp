#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str[4]{
        "ABBT",
        "BTBT&",
        "BBBT",
        "KFC"};

    for (int i = 0; i < 4; i++)
    {
        for (int j = str[i].length() - 1; j >= 0; j--)
        {
            cout << str[i][j];
        }
        cout << '\n';
    }

    return 0;
}
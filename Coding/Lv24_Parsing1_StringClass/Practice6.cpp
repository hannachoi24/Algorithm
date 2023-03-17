#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str[4]{
        "ABBT",
        "BTBT",
        "BBBT",
        "KFC"};

    for (int i = 0; i < 4; i++)
    {
        if (str[i].find("BB") == -1)
        {
            cout << "X" << '\n';
        }
        else
            cout << "O" << '\n';
    }

    return 0;
}
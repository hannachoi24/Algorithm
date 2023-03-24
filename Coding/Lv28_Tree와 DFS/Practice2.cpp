#include <iostream>
#include <string>
using namespace std;

int map[5][5] = {
    0, 1, 0, 0, 0,
    0, 0, 1, 1, 0,
    0, 1, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 1, 0, 0, 0};

int main()
{
    char ch;
    cin >> ch;

    int n = ch - 'A';

    for (int i = 0; i < 5; i++)
    {
        if (map[n][i] == 1)
        {
            cout << (char)('A' + i);
        }
    }

    return 0;
}
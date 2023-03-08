#include <iostream>
using namespace std;

int map[4][4];

int main()
{
    char ch;
    int n;

    for (int i = 0; i < 3; i++)
    {
        cin >> ch >> n;

        if (ch == 'G')
        {
            for (int j = 0; j < 4; j++)
            {
                map[n][j] = 1;
            }
        }

        else if (ch == 'S')
        {
            for (int i = 0; i < 4; i++)
            {
                map[i][n] = 1;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
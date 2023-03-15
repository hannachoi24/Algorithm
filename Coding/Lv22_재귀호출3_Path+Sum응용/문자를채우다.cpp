#include <iostream>
using namespace std;

int main()
{
    char map[3][3][3];
    char a;
    cin >> a;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                map[0][j][k] = a;
                map[1][j][k] = a + 1;
                map[2][j][k] = a + 2;

                cout << map[i][j][k];
            }
            cout << '\n';
        }
        cout << '\n';
    }

    return 0;
}

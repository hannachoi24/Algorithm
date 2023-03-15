#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int map[3][2][3] = {0};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                map[i][0][k] = a;
                map[i][1][k] = b;

                cout << map[i][j][k] << " ";
            }
            cout << '\n';
        }
        cout << '\n';
    }

    return 0;
}
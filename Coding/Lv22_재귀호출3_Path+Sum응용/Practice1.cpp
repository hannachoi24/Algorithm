#include <iostream>
using namespace std;

int main()
{
    int v[2][3][4] = {0};

    v[1][0][2] = 7;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                cout << v[i][j][k];
            }
            cout << endl;
        }
        cout << "======" << endl;
    }
    return 0;
}
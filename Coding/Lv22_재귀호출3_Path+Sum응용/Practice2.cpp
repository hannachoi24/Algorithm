#include <iostream>
using namespace std;

int main()
{
    int v[2][2][2][3] = {0};

    v[0][0][1][2] = 4;
    v[0][1][1][1] = 7;
    v[1][0][1][2] = 3;
    v[1][1][1][1] = 9;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                for (int z = 0; z < 3; z++)
                {
                    cout << v[i][j][k][z];
                }
                cout << endl;
            }
            cout << endl;
        }
        cout << "======" << endl;
    }
    return 0;
}
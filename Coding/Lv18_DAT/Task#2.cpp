#include <iostream>
using namespace std;

int main()
{

    int map[3][4];
    int dat[10] = {0};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> map[i][j];
            dat[map[i][j]]++;
        }
    }

    for (int k = 1; k < 10; k++)
    {

        if (dat[k] == 0)
        {
            cout << k << " ";
        }
    }

    return 0;
}
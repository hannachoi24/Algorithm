#include <iostream>
using namespace std;

int map[2][3] = {
    3, 55, 42,
    -5, -9, -10};

int pix[2][2];

int isExist(int target)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (map[i][j] == target)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> pix[i][j];
        }
    }

    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 2; y++)
        {
            if (isExist(pix[x][y]))
            {
                cout << "Y ";
            }
            else
            {
                cout << "N ";
            }
        }
        cout << '\n';
    }

    return 0;
}

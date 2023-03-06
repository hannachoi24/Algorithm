#include <iostream>
using namespace std;

int arr[6] = {3, 7, 4, 1, 2, 6};
int univer[2][2];

int isExist(int target)
{
    for (int i = 0; i < 6; i++)
    {
        if (arr[i] == target)
        {
            return 1;
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
            cin >> univer[i][j];
        }
    }

    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 2; y++)
        {
            if (isExist(univer[x][y]))
            {
                cout << "OK ";
            }
            else
            {
                cout << "NO ";
            }
        }
        cout << '\n';
    }

    return 0;
}
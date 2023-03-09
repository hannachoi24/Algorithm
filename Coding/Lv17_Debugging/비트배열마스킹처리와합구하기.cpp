#include <iostream>
using namespace std;

int main()
{
    int arr[3][3] = {
        3, 5, 9,
        4, 2, 1,
        1, 1, 5};

    int bitarr[3][3] = {0};

    int x = 0;
    int y = 0;
    int sum = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> bitarr[i][j];

            if (bitarr[i][j] == 1)
            {
                x = i;
                y = j;
                sum += map[x][y];
            }
        }
    }

    cout << sum;

    return 0;
}

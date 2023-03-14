#include <iostream>
using namespace std;

int arr[3][4] = {
    3, 4, 1, 5,
    3, 4, 1, 3,
    5, 2, 3, 6};

int sum[4];

int main()
{
    int i, j;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            sum[i] += arr[j][i];
        }
    }

    int index;
    cin >> index;

    cout << sum[index];

    return 0;
}
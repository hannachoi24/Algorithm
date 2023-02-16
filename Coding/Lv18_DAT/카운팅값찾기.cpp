#include <iostream>
using namespace std;

int main()
{
    int arr[3][5] = {
        {1, 3, 3, 5, 1},
        {3, 6, 2, 4, 2},
        {1, 9, 2, 6, 5}};

    int dat[10] = {0};

    int n;
    cin >> n;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            dat[arr[i][j]]++;
        }
    }

    for (int k = 1; k < 10; k++)
    {
        if (dat[k] == n)
        {
            cout << k << " ";
        }
    }

    return 0;
}
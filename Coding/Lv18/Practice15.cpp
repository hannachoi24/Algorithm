#include <iostream>
using namespace std;

// Direct Address Datatable

int main()
{
    int arr[2][4] = {1, 5, 10, 15, 15, 15, 17, 10};

    int dat[31] = {0};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            dat[arr[i][j]]++;
        }
    }

    int n;
    cin >> n;

    cout << dat[n];

    return 0;
}
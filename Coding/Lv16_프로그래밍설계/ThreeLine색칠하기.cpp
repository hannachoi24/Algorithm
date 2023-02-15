#include <iostream>
using namespace std;

int main()
{
    int arr[7][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20},
        {21, 22, 23, 24},
        {25, 26, 27, 28}};

    int a, b, c;
    cin >> a >> b >> c;

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 4; j++)
        {

            arr[a][j] = 0;
            arr[b][j] = 0;
            arr[c][j] = 0;
        }
    }

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}

/* 또 다른 정답 코드
int main()
{
    int arr[7][4];
    int y, x;
    int index1, index2, index3;
    int t = 1;

    for (y = 0; y < 7; y++)
    {
        for (x = 0; x < 4; x++)
        {
            arr[y][x] = t;
            t++;
        }
    }

    cin >> index1 >> index2 >> index3;
    for (x = 0; x < 4; x++)
    {
        arr[index1][x] = 0;
        arr[index2][x] = 0;
        arr[index3][x] = 0;
    }

    for (y = 0; y < 7; y++)
    {
        for (x = 0; x < 4; x++)
        {
            cout << arr[y][x] << " ";
        }
        cout << endl;
    }

    return 0;
}*/
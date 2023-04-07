#include <iostream>
using namespace std;

char arr1[4][5] = {
    {'A', 'B', 'C', 'D'},
    {'B', 'B', 'A', 'B'},
    {'C', 'B', 'A', 'C'},
    {'B', 'A', 'A', 'A'}};

char arr2[4][4];
int dat[200] = {0};

int main()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr2[i][j];
        }
    }

    int maxCnt = -21e8;
    char result;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr1[i][j] == arr2[i][j])
            {
                dat[arr1[i][j]]++;
            }

            if (dat[arr1[i][j]] > maxCnt)
            {
                maxCnt = dat[arr1[i][j]];
                result = arr1[i][j];
            }
        }
    }

    cout << result;

    return 0;
}
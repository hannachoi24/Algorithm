#include <iostream>
#include <string>
using namespace std;

int dat[100];

char arr[2][4];

int isExit()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dat[arr[i][j]]++;

            if (dat[arr[i][j]] >= 3)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{

    arr[0][0] = 'G';
    arr[0][1] = 'K';
    arr[0][2] = 'G';

    for (int j = 0; j < 3; j++)
    {
        cin >> arr[1][j];
    }

    if (isExit())
    {
        cout << "있음";
    }
    else
    {
        cout << "없음";
    }

    return 0;
}
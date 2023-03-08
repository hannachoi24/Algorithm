#include <iostream>
using namespace std;

int arr[4][4] = {
    1, 2, 3, 4,
    5, 6, 7, 8,
    9, 10, 11, 12,
    13, 14, 15, 16};

int target[4];

int dat[4][4];

int n;

void isExist(int target)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] == target)
            {
                dat[i][j] = n + 1;
                n++;
            }
        }
    }
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        cin >> target[i];

        isExist(target[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << dat[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}

/* 또 다른 코드
#include<iostream>
using namespace std;

int main()
{
    int input[4];
    int map[4][4];
    int result[4][4] = { 0 };

    //입력
    for (int i = 0; i < 4; i++)
    {
        cin >> input[i];
    }

    //1~16 값 채우기
    int t = 1;
    int x, y;
    for (y = 0; y < 4; y++)
    {
        for (x = 0; x < 4; x++)
        {
            map[y][x] = t;
            t++;
        }
    }

    //result 채우기
    int flag;
    for (t = 0; t < 4; t++)
    {
        flag = 0;
        for (y = 0; y < 4; y++)
        {
            for (x = 0; x < 4; x++)
            {
                if (map[y][x] == input[t])
                {
                    result[y][x] = t + 1;
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) break;
        }
    }

    //출력
    for (y = 0; y < 4; y++)
    {
        for (x = 0; x < 4; x++)
        {
            cout << result[y][x] << " ";
        }
        cout << endl;
    }

    return 0;
}
*/
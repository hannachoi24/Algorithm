#include <iostream>
using namespace std;

int map[2][4] = {
    5,
    5,
    2,
    6,
    9,
    1,
    1,
    3,
};

int tar[8] = {5, 6, 1, 1, 1, 1, 5, 4};

int getCount(int n)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        if (tar[i] == n)
            cnt++;
    }
    return cnt;
}

int main()
{
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            int ret = getCount(map[x][y]);
            cout << ret;
        }
        cout << endl;
    }

    return 0;
}
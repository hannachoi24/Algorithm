#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string name = "ECADF";

    int map[5][5] = {
        0, 1, 0, 1, 0,
        0, 0, 0, 0, 1,
        1, 1, 0, 1, 0,
        0, 1, 0, 0, 1,
        0, 0, 1, 0, 0};

    // 1. A가 좋아하는 사람들(가로 탐색)
    for (int i = 0; i < 5; i++)
    {
        if (map[2][i] == 0)
            continue;

        cout << name[i];
    }

    // 2. 인기가 가장 많은 사람(세로 탐색)
    int maxCnt = 0;
    int maxIndex = 0;

    for (int x = 0; x < 5; x++)
    {
        int cnt = 0;
        for (int y = 0; y < 5; y++)
        {
            if (map[y][x] == 1)
                cnt++;
        }

        if (cnt > maxCnt)
        {
            maxCnt = cnt;
            maxIndex = x;
        }
    }

    cout << name[maxIndex];

    return 0;
}
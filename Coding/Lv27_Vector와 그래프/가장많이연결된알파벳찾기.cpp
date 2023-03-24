#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string name = "ABCD";
    int map[4][4];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> map[i][j];
        }
    }

    // 가장 많이 연결된 알파벳을 찾아 출력합니다.
    int maxCnt = 0;
    int maxIdx = 0;
    for (int x = 0; x < 4; x++)
    {
        int cnt = 0;
        for (int y = 0; y < 4; y++)
        {
            if (map[y][x] == 1)
            {
                cnt++;
            }

            if (cnt > maxCnt)
            {
                maxCnt = cnt;
                maxIdx = x;
            }
        }
    }

    cout << name[maxIdx];

    return 0;
}
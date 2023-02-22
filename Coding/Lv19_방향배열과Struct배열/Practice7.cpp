#include <iostream>
using namespace std;

// 패턴 찾기(isSame 함수 안 만들고 하는 방법)

char map[4][5] = {
    "ABAB",
    "BTBT",
    "KABK",
    "KBTK"};

char tar[2][3] = {
    "AB",
    "BT"};

int main()
{
    int cnt = 0;
    for (int i = 0; i <= 4 - 2; i++)
    {
        for (int j = 0; j <= 4 - 2; j++)
        {
            int flag = 0;

            for (int x = 0; x < 2; x++)
            {
                for (int y = 0; y < 2; y++)
                {
                    if (map[i + x][j + y] != tar[x][y])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag)
                    break;
            }
            if (flag == 0)
                cnt++;
        }
    }

    cout << cnt;

    return 0;
}
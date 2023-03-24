#include <iostream>
using namespace std;

int main()
{
    char map[4][4];

    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

    // 초기화
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            map[i][j] = '_';
        }
    }

    // 아기돼지집 위치 입력받기
    for (int t = 0; t < 3; t++)
    {
        int x, y;
        cin >> x >> y;
        map[x][y] = '#';
    }

    // 벽 세우기
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (map[i][j] == '#')
            {
                for (int k = 0; k < 8; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && map[nx][ny] != '#')
                    {
                        map[nx][ny] = '@';
                    }
                }
            }
        }
    }

    // 출력
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << map[i][j];
        }
        cout << '\n';
    }

    return 0;
}

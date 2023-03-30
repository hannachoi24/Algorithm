#include <iostream>
using namespace std;

int main()
{
    const int n = 4;
    const int m = 3;
    char map[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    // 5초 후 MAP 출력하기
    for (int t = 0; t < 5; t++)
    {
        // 각 몬스터의 이동 방향
        int dx[] = {0, 1, 0, -1}; // 상하좌우 순서
        int dy[] = {1, 0, -1, 0};

        // 각 몬스터 이동하기
        for (char c = 'A'; c <= 'Z'; c++)
        {
            int x = -1, y = -1;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (map[i][j] == c) // 몬스터가 있는 위치 저장
                    {
                        x = i;
                        y = j;
                        break;
                    }
                }
                if (x != -1)
                    break;
            }
            if (x != -1) // 몬스터가 있는 경우
            {
                int dir = t % 4; // 이동 방향
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == '_')
                {
                    map[nx][ny] = c;
                    map[x][y] = '_';
                }
            }
        }
    }

    // MAP 출력하기
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << map[i][j];
        }
        cout << '\n';
    }

    return 0;
}

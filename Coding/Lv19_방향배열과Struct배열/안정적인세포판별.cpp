#include <iostream>
#include <queue>
using namespace std;

int map[5][4];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

struct Node
{
    int x, y;
};

queue<Node> q;

int bfs()
{
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for (int k = 0; k < 8; k++)
        {
            // 1이 있는 위치에서 부터 주변 탐색
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 4)
                continue;

            if (map[nx][ny] != 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    // 그래프 정보 입력 및 배열에서 1의 위치 저장
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 1)
            {
                q.push({i, j});
            }
        }
    }

    if (bfs())
    {
        cout << "안정된 상태";
    }
    else
    {
        cout << "불안정한 상태";
    }

    return 0;
}

/* 또 다른 코드
#include<iostream>
using namespace std;

int map[5][4];

int isStable(int y, int x)
{
    int direct[8][2] =
    {
        -1,-1,
        -1,0,
        -1,1,
        0,-1,
        0,1,
        1,-1,
        1,0,
        1,1
    };

    int dy, dx, t;
    for (t = 0; t < 8; t++)
    {
        dy = y + direct[t][0];
        dx = x + direct[t][1];
        if (dy >= 0 && dy < 5 && dx >= 0 && dx < 4)
        {
            if (map[dy][dx] == 1)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int x, y;

    for (y = 0; y < 5; y++)
    {
        for (x = 0; x < 4; x++)
        {
            cin >> map[y][x];
        }
    }

    int flag = 0;
    for (y = 0; y < 5; y++)
    {
        for (x = 0; x < 4; x++)
        {
            //불안정된 곳을 찾았다면 flag = 1
            if (map[y][x] == 1 && isStable(y, x) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1) break;
    }

    if (flag == 0) cout << "안정된 상태";
    else cout << "불안정한 상태";

    return 0;
}
*/
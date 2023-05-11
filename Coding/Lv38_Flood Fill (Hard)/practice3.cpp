#include <iostream>
#include <queue>

using namespace std;

// 폭탄이 다 터지는 시간 구하기

int map[4][7] = {
    0, 1, 1, 1, 1, 0, 1,
    0, 0, 0, 2, 1, 0, 1,
    2, 1, 0, 0, 0, 0, 0,
    1, 1, 1, 0, 2, 2, 0};

int visited[4][7];

struct Node
{
    int x, y, lev;
};

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

queue<Node> q;

void init()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (map[i][j] != 2)
                continue;

            q.push({i, j});
            visited[i][j] = true;
        }
    }
}

int bfs()
{
    int lastLev = 0;

    while (!q.empty())
    {
        Node now = q.front();
        q.pop();

        for (int t = 0; t < 4; t++)
        {
            int nx = now.x + dx[t];
            int ny = now.y + dy[t];

            if (nx < 0 || nx >= 4 || ny < 0 || ny >= 7)
                continue;

            if (map[nx][ny] == 1) // 벽이면
                continue;
            if (visited[nx][ny] = true)
                continue;

            visited[nx][ny] = true;
            q.push({nx, ny, now.lev + 1});

            lastLev = now.lev + 1;
        }
    }
    return lastLev;
}

int main()
{
    init();

    cout << bfs();

    return 0;
}
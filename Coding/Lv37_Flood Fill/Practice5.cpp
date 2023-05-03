#include <iostream>
#include <queue>

using namespace std;

// 미로 탈출

struct Node
{
    int x, y, lev;
};

int map[5][5] = {
    0, 0, 1, 1, 1,
    1, 0, 0, 0, 1,
    1, 1, 1, 0, 1,
    0, 0, 0, 0, 1,
    1, 0, 1, 0, 0};

bool visited[5][5];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

queue<Node> q;

int tarX = 4;
int tarY = 4;

int bfs(int sx, int sy)
{
    q.push({sx, sy});
    visited[sx][sy] = true;

    while (!q.empty())
    {
        Node now = q.front();
        int x = now.x;
        int y = now.y;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
                continue;

            if (map[nx][ny] == 0 && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                q.push({nx, ny, now.lev + 1});

                if (nx == tarX && ny == tarY)
                {
                    return now.lev + 1;
                }
            }
        }
    }
    return 0; // 못 찾았으면
}

int main()
{
    cout << bfs(0, 0);

    return 0;
}
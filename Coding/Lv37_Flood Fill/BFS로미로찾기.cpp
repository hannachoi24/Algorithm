#include <iostream>
#include <queue>

using namespace std;

// 미로 찾기

struct Node
{
    int x, y, lev;
};

int map[4][4] = {
    0, 0, 0, 0,
    1, 1, 0, 1,
    0, 0, 0, 0,
    1, 0, 1, 0};

bool visited[4][4];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

queue<Node> q;

int bfs(int startX, int startY, int endX, int endY)
{
    q.push({startX, startY});
    visited[startX][startY] = true;

    int cnt = 0;
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

            if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4)
                continue;

            if (map[nx][ny] != 0)
                continue;

            if (map[nx][ny] == 0 && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                q.push({nx, ny, now.lev + 1});

                if (nx == endX && ny == endY)
                {
                    return now.lev + 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    int sX, sY, eX, eY;
    cin >> sX >> sY;
    cin >> eX >> eY;

    cout << bfs(sX, sY, eX, eY) << "회";

    return 0;
}
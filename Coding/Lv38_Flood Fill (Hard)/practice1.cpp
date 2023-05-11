#include <iostream>
#include <queue>

using namespace std;

// 1에서 2까지 가는데 필요한 징검다리 수

int map[4][6] = {
    0, 0, 0, 0, 0, 2,
    0, 1, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 2,
    0, 0, 0, 2, 2, 2};

int visited[4][6];

struct Node
{
    int x, y, lev;
};

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

queue<Node> q;

int bfs()
{
    q.push({1, 1});
    visited[1][1] = true;

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

            if (nx < 0 || nx >= 4 || ny < 0 || ny >= 6)
                continue;

            if (map[nx][ny] != 1 && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                q.push({nx, ny, now.lev + 1});

                if (map[nx][ny] == 2)
                {
                    return now.lev + 1;
                }
            }
        }
    }
    return -1;
}

int main()
{
    cout << bfs() - 1;

    return 0;
}
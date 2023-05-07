#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int x, y;
};

int map[4][6];
bool visited[4][6];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

queue<Node> q;

int bfs(int x, int y)
{
    q.push({x, y});
    visited[x][y] = true;

    int cnt = 0;
    while (!q.empty())
    {
        Node now = q.front();

        int cx = now.x;
        int cy = now.y;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= 4 || ny < 0 || ny >= 6)
                continue;

            if (visited[nx][ny] || map[nx][ny] == 1) // 방문했거나 벽이면 건너뛰기
                continue;

            visited[nx][ny] = true;

            if (map[nx][ny] == 2) // 이동한 위치가 치킨인 경우
            {
                cnt++; // 치킨 먹음
            }

            q.push({nx, ny});
        }
    }

    return cnt;
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> map[i][j];
        }
    }

    cout << bfs(0, 0);

    return 0;
}
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

// 시골쥐가 치즈를 먹고 도시 쥐에게 가기까지의 최단 거리

int n, m;

struct Node
{
    int x, y, t;
};

char map[21][21];
bool visited[21][21];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int bfs(Node start, Node end)
{
    memset(visited, false, sizeof(visited));
    queue<Node> q;
    q.push(start);
    visited[start.x][start.y] = true;

    while (!q.empty())
    {
        Node now = q.front();

        int x = now.x;
        int y = now.y;
        int t = now.t;
        q.pop();

        if (x == end.x && y == end.y)
        {
            return t;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (map[nx][ny] == 'x' || visited[nx][ny])
                continue;

            visited[nx][ny] = true;
            q.push({nx, ny, t + 1});
        }
    }

    return -1;
}

int main()
{
    cin >> n >> m;

    Node start, end, cheese;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'S')
            {
                start = {i, j, 0};
            }
            else if (map[i][j] == 'D')
            {
                end = {i, j, 0};
            }
            else if (map[i][j] == 'C')
            {
                cheese = {i, j, 0};
            }
        }
    }

    int start_to_cheese = bfs(start, cheese);
    int cheese_to_end = bfs(cheese, end);

    int total_time = start_to_cheese + cheese_to_end;

    cout << total_time;

    return 0;
}

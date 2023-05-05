#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int x, y;
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int map[100][100];
bool visited[100][100];

queue<Node> q;

int main()
{
    int n, m;
    int x, y;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    cin >> x >> y;

    q.push({x, y});
    visited[x][y] = true;

    int result = 0;
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (map[nx][ny] != 0)
                continue;

            if (map[nx][ny] == 0 && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                map[nx][ny] = map[x][y] + 1;
                q.push({nx, ny});
                result = map[nx][ny];
            }
        }
    }

    cout << result;

    return 0;
}

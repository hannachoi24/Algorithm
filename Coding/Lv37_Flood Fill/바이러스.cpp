#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int x, y;
};

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int map[100][100];
bool visited[100][100];

queue<Node> q;

int main()
{
    int n;
    int x1, y1, x2, y2;
    cin >> n;
    cin >> x1 >> y1 >> x2 >> y2;

    map[x1][y1] = 1;
    map[x2][y2] = 1;
    q.push({x1, y1});
    q.push({x2, y2});
    visited[x1][y1] = true;
    visited[x2][y2] = true;

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;

            if (map[nx][ny] != 0)
                continue;

            if (map[nx][ny] == 0 && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                map[nx][ny] = map[x][y] + 1;
                if (map[ny][nx] > 9)
                    map[ny][nx] = 9;
                q.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << map[i][j];
        }
        cout << '\n';
    }

    return 0;
}
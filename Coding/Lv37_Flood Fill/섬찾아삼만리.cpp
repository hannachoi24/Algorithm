#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// 섬의 개수

int height;
int width;
int map[100][100];

struct Node
{
    int x, y;
};

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

queue<Node> q;

void bfs(int startX, int startY)
{
    map[startX][startY] = 0;
    q.push({startX, startY});

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

            if (nx < 0 || nx >= height || ny < 0 || ny >= width)
                continue;

            if (map[nx][ny] == 0)
                continue;
            map[nx][ny] = 0;
            q.push({nx, ny});
        }
    }
}

void input()
{
    cin >> height >> width;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cin >> map[i][j];
        }
    }
}

int main()
{
    input();

    int cnt = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (map[i][j] == 0)
                continue;
            bfs(i, j);
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
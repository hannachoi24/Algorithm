#include <iostream>
#include <queue>

using namespace std;

// Flood Fill

struct Node
{
    int x, y;
};

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int map[3][3] = {0};

queue<Node> q;

int main()
{
    // 출발 지점
    map[1][2] = 1;
    q.push({1, 2});

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3)
                continue;

            if (map[nx][ny] != 0)
                continue;

            map[nx][ny] = map[x][y] + 1;
            q.push({nx, ny});
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
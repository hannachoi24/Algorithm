#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int x, y;
};

int map[3][3];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

queue<Node> q;

int main()
{
    map[1][0] = 1;
    map[0][2] = 1;

    q.push({1, 0});
    q.push({0, 2});

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

            if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3)
                continue;

            if (map[nx][ny] != 0)
                continue;

            map[nx][ny] = map[x][y] + 1;
            q.push({nx, ny});

            result = map[nx][ny];
        }
    }

    cout << result;

    return 0;
}
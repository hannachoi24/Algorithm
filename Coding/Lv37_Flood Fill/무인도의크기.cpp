#include <iostream>
#include <queue>

using namespace std;

// 입력 받은 좌표(영역) 내에서 섬의 개수

struct Node
{
    int x, y;
};

int map[4][4];
bool visited[4][4];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

queue<Node> q;

int main()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> map[i][j];
        }
    }

    q.push({0, 0});
    visited[0][0] = true;

    int cnt = 1;
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4)
                continue;

            if (map[nx][ny] == 1 && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}
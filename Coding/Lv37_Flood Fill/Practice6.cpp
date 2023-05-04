#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// 시골쥐가 치즈를 먹고 도시 쥐에게 가기까지의 최단 거리

struct Node
{
    int x, y, lev;
};

int map[3][6] = {
    0, 0, 0, 0, 1, 0,
    1, 1, 1, 0, 1, 0,
    0, 0, 0, 0, 0, 0};

int visited[3][6];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

queue<Node> q;

int bfs(int startX, int startY, int endX, int endY)
{
    while (!q.empty())
        q.pop();
    memset(visited, 0, 3 * 6 * 4); // 4: int size를 의미(4byte)

    q.push({startX, startY});
    visited[startX][startY] = 1;

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

            if (nx < 0 || nx >= 3 || ny < 0 || ny >= 6)
                continue;

            if (map[nx][ny] == 1)
                continue;
            if (visited[nx][ny] == 1)
                continue;

            visited[nx][ny] = 1;
            q.push({nx, ny, now.lev + 1});

            if (nx == endX && ny == endY)
            {
                return now.lev + 1;
            }
        }
    }
    return 0; // 못 찾았으면
}

int main()
{
    int result = 0;
    result += bfs(0, 0, 2, 0);
    result += bfs(2, 0, 0, 5);

    cout << result;

    return 0;
}
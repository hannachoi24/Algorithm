#include <iostream>
#include <queue>

using namespace std;

// 비어 있는 곳에 물감을 퍼뜨린 횟수 출력

struct Node
{
    int x, y;
};

int map[4][4] = {
    1, 0, 1, 1,
    0, 0, 0, 1,
    0, 3, 0, 2,
    3, 2, 0, 0};

bool visited[4][4];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

queue<Node> q;

int main()
{
    q.push({1, 2});
    cnt++;
    visited[1][2] = true;

    int cnt = 0;
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

            if (map[nx][ny] == 0 && !visited[nx][ny])
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
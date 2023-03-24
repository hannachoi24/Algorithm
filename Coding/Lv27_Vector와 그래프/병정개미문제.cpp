#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int x, y;
};

int bfs()
{
    int map[4][4];
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    queue<Node> q;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 1)
            {
                q.push({i, j});
            }
        }
    }

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

            if (map[nx][ny] == 1)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    if (bfs())
    {
        cout << "안전한 상태";
    }
    else
    {
        cout << "위험한 상태";
    }

    return 0;
}

/* 또 다른 코드
#include<iostream>
using namespace std;
int main() {
    int arr[4][4];
    int dir[4][2] = {
        -1,0,
        1,0,
        0,-1,
        0,1
    };
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[i][j];
        }
    }
    bool safe = true;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (arr[i][j] == 1) {
                for (int k = 0; k < 4; k++) {
                    int dx = i + dir[k][0];
                    int dy = j + dir[k][1];
                    if (dx >= 0 && dx < 4 && dy >= 0 && dy < 4) {
                        if (arr[dx][dy] == 1) {
                            safe = false;
                            break;
                        }
                    }
                }
            }
        }
    }
    if (safe)
        cout << "안전한 상태";
    else
        cout << "위험한 상태";
    return 0;
}
*/
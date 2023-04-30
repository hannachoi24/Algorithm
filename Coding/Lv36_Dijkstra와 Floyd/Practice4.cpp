#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 최소의 피로도 구하기

struct Node
{
    int x, y;
    int price;
};

int map[4][4] = {
    2, 2, 1, 1,
    3, 1, 30, 1,
    0, 20, 50, 2,
    2, 5, 3, 0};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool operator<(Node a, Node b)
{
    return a.price > b.price;
}

priority_queue<Node> q;

int result[4][4];

void init()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            result[i][j] = 21e8;
        }
    }

    // 출발 지점
    result[1][1] = 1;

    q.push({1, 1, 1});
}

int main()
{
    init();

    while (!q.empty())
    {
        Node now = q.top();
        q.pop();

        if (result[now.x][now.y] < now.price)
            continue;

        for (int t = 0; t < 4; t++)
        {
            int nx = now.x + dx[t];
            int ny = now.y + dy[t];

            if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4)
                continue;

            int priceSum = now.price + map[nx][ny];

            if (result[nx][ny] > priceSum)
            {
                result[nx][ny] = priceSum;
                q.push({nx, ny, priceSum});
            }
        }
    }

    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

int map[5][5] = {
    {3, 3, 5, 3, 1},
    {2, 2, 4, 2, 6},
    {4, 9, 2, 3, 4},
    {1, 1, 1, 1, 1},
    {3, 3, 5, 9, 2}};

int dx[4] = {-1, 1, -1, 1};
int dy[4] = {-1, -1, 1, 1};

struct Node
{
    int x, y;
};

queue<Node> q;

int main()
{

    int max = -99;
    int max_x = 0;
    int max_y = 0;

    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            q.push({i, j});
        }
    }

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        int sum = 0;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            sum += map[nx][ny];
        }

        if (sum > max)
        {
            max = sum;
            max_x = x;
            max_y = y;
        }
    }

    cout << max_x << " " << max_y;

    return 0;
}
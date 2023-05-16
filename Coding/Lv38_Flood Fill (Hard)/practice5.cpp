#include <iostream>
#include <queue>

using namespace std;

// 탱크를 전진, 후진, 90도 회전을 통해 다른 탱크가 있는 곳 까지 최단 경로

struct Node
{
    int x, y;
    int lev;
    int dir;
};

enum
{
    UP = 1,
    DOWN,
    LEFT,
    RIGHT,
};

int map[3][4] = {
    0, 0, 1, 0,
    1, 0, 1, 0,
    0, 0, 0, 0};

int tarY = 0;
int tarX = 3;
int tarDir = DOWN;

bool visited[3][4][5];

queue<Node> q;

void push(int y, int x, int dir, int lev)
{
    if (y < 0 || y >= 3 || x < 0 || x >= 4)
        return;
    if (visited[y][x][dir] == true)
        return;
    if (map[y][x] == 1)
        return; // 벽이면
    visited[y][x][dir] = true;
    q.push({y, x, dir, lev});
}

int bfs()
{
    while (!q.empty())
    {
        Node now = q.front();
        q.pop();

        if (now.x == tarX && now.y == tarY && now.dir == tarDir)
            return now.lev;

        if (now.dir == UP)
        {
            push(now.y - 1, now.x, UP, now.lev + 1); // 전진
            push(now.y + 1, now.x, UP, now.lev + 1); // 후진
        }

        if (now.dir == DOWN)
        {
            push(now.y + 1, now.x, DOWN, now.lev + 1); // 전진
            push(now.y - 1, now.x, DOWN, now.lev + 1); // 후진
        }

        if (now.dir == RIGHT)
        {
            push(now.y, now.x + 1, RIGHT, now.lev + 1); // 전진
            push(now.y, now.x - 1, RIGHT, now.lev + 1); // 후진
        }

        if (now.dir == LEFT)
        {
            push(now.y, now.x - 1, LEFT, now.lev + 1); // 전진
            push(now.y, now.x + 1, LEFT, now.lev + 1); // 후진
        }

        if (now.dir == UP || now.dir == DOWN)
        {
            push(now.y, now.x, RIGHT, now.lev + 1);
            push(now.y, now.x, LEFT, now.lev + 1);
        }

        if (now.dir == LEFT || now.dir == RIGHT)
        {
            push(now.y, now.x, UP, now.lev + 1);
            push(now.y, now.x, DOWN, now.lev + 1);
        }
    }

    return -1;
}

int main()
{
    q.push({0, 0, RIGHT});
    visited[0][0][RIGHT] = true;

    cout << bfs();

    return 0;
}
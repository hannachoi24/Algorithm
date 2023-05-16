#include <iostream>
#include <queue>

using namespace std;

// 더블 리모콘

struct Node
{
    int n;
    int lev;
};

bool visited[1000];

queue<Node> q;

void push(int n, int lev)
{
    if (visited[n] == true)
        return;

    visited[n] = true;
    q.push({n, lev});
}

int bfs()
{
    while (!q.empty())
    {
        Node now = q.front();
        q.pop();

        if (now.n == 27) // 큐에 등록이될 때 종료
            return now.lev;

        push(now.n + 1, now.lev + 1);
        push(now.n - 1, now.lev + 1);
        push(now.n * 2, now.lev + 1);
        push(now.n / 2, now.lev + 1);
    }
    return 0;
}

int main()
{
    q.push({7, 0});
    visited[7] = true;

    cout << bfs();

    return 0;
}
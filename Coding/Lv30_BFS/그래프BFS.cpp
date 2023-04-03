#include <iostream>
#include <queue>
using namespace std;

int map[6][6] = {
    0, 0, 0, 0, 1, 0,
    1, 0, 1, 0, 0, 1,
    1, 0, 0, 1, 0, 0,
    1, 1, 0, 0, 0, 0,
    0, 1, 0, 1, 0, 1,
    0, 0, 1, 1, 0, 0};

int start;

void bfs(int now)
{
    queue<int> q;
    bool visited[10] = {false};

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int now = q.front();
        cout << now << '\n';
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            if (map[now][i] == 0)
                continue;
            if (visited[i] == true)
                continue;
            visited[i] = true;
            q.push(i);
        }
    }
}

int main()
{
    cin >> start;
    bfs(start);
    return 0;
}
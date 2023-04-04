#include <iostream>
#include <queue>
using namespace std;

int map[6][6] = {
    0, 1, 0, 0, 1, 0,
    0, 0, 1, 0, 0, 1,
    0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0};

int start;

void bfs(int now)
{
    bool visited[10] = {false};
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int now = q.front();
        cout << now << " ";
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
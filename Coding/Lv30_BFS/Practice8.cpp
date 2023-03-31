#include <iostream>
#include <queue>
#include <string>
using namespace std;

// a->b 까지 최소 이동 수

int a, b;
string name = "ABCDE";

int map[5][5] = {
    0, 1, 0, 0, 0,
    0, 0, 0, 1, 1,
    1, 0, 0, 0, 0};

int minLev = 21e8;
void bfs(int level, int start)
{
    queue<char> q;
    bool visited[5] = {false};

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        if (now == b)
        {
            if (level < minLev)
                minLev = level;
            return;
        }

        for (int i = 0; i < 5; i++)
        {
            if (map[now][i] == 0)
                continue;
            if (visited[i] == true)
                continue;
            visited[i] = true;

            bfs(level + 1, i);

            q.push(i);
        }
    }
}

int main()
{
    cin >> a >> b;
    bfs(0, a);
    cout << minLev;
    return 0;
}
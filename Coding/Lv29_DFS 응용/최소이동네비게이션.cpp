#include <iostream>
using namespace std;

// A에서 B까지 가기 위한 최소 이동 횟수 출력

int map[6][6] = {
    0, 0, 1, 0, 1, 1,
    1, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 1, 0,
    1, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0};

int a, b;
bool visited[10] = {false};
int mini = 21e8;

void dfs(int level, int now)
{
    if (now == b)
    {
        if (mini > level)
            mini = level;
        return;
    }

    for (int i = 0; i < 6; i++)
    {
        if (map[now][i] == 0)
            continue;
        if (visited[i] == true)
            continue;
        visited[i] = true;
        dfs(level + 1, i);
        visited[i] = 0;
    }
}

int main()
{
    cin >> a >> b;
    a--;
    b--;

    visited[a] = true;
    dfs(0, a);

    if (mini == 21e8)
        mini = 0;
    cout << mini;

    return 0;
}
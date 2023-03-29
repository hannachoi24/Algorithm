#include <iostream>
using namespace std;

// a -> b 경로 수

int map[6][6] = {
    0, 2, 6, 3, 0, 0,
    2, 0, 7, 4, 0, 0,
    6, 7, 0, 0, 0, 0,
    3, 4, 2, 0, 0, 0,
    0, 0, 1, 0, 0, 7,
    0, 0, 0, 0, 0, 0};

bool visited[6] = {false};
int a, b;
int cnt = 0;

void dfs(int now)
{
    if (now == b)
    {
        cnt++;
        return;
    }

    for (int i = 0; i < 6; i++)
    {
        if (map[now][i] == 0)
            continue;
        if (visited[i] == true)
            continue;
        visited[i] = true;
        dfs(i);
    }
}

int main()
{
    cin >> a >> b;

    dfs(a);

    cout << cnt;

    return 0;
}
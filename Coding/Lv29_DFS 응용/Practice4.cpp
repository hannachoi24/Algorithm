#include <iostream>
#include <vector>
using namespace std;

// 모든 경로를 1회씩 탐색 (visited 돌아오면서 지우면 됨)
// 모든 노드 1회씩 탐색 (visited 지우지 않음)

int map[3][3] = {
    0, 1, 1,
    0, 0, 1,
    1, 0, 0};

bool visited[3] = {false};

int cnt = 0;

void dfs(int now)
{
    if (now == 2)
    {
        cnt++;
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        if (map[now][i] == 0)
            continue;
        if (visited[i] == true)
            continue;
        visited[i] = true;
        dfs(i);
        visited[i] = false; // 지움, 다음에 또 가기위해
    }
}

int main()
{
    visited[0] = true;
    dfs(0);
    cout << cnt;
    return 0;
}
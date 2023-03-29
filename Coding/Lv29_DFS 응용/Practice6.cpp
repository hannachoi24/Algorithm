#include <iostream>
#include <vector>
using namespace std;

// 가중치 그래프 2에 도착 했을 때 가중치 sum 출력하세요

int map[4][4] = {
    0, 7, 20, 8,
    0, 0, 5, 0,
    15, 0, 0, 0,
    0, 0, 6, 0};

bool visited[4] = {false};

void dfs(int now, int sum)
{
    if (now == 2) // 2에 도착했을 때
    {
        cout << sum << " ";
    }

    for (int i = 0; i < 4; i++)
    {
        if (map[now][i] == 0)
            continue;
        if (visited[i] == true)
            continue;
        visited[i] = true;
        dfs(i, sum + map[now][i]);
        visited[i] = false;
    }
}

int main()
{
    visited[0] = true;
    dfs(0, 0);
    return 0;
}
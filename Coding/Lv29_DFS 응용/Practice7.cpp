#include <iostream>
#include <vector>
using namespace std;

// 모든 노드 1회 탐색하기(단, 4번부터 출발)

int map[6][6] = {
    0, 2, 6, 3, 0, 0,
    2, 0, 7, 4, 0, 0,
    6, 7, 0, 0, 0, 0,
    3, 4, 2, 0, 0, 0,
    0, 0, 1, 0, 0, 7,
    0, 0, 0, 0, 0, 0};

bool visited[6] = {false};

void dfs(int now)
{
    cout << now << " ";
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
    dfs(4);
    return 0;
}
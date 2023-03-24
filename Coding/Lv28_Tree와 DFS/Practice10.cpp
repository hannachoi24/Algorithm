#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 트리(사이클x)
// DFS

string name = "ABTQVX";
int map[6][6] = {
    0, 1, 1, 1, 0, 0,
    0, 0, 0, 0, 1, 1}; // 안 채워준 나머지는 0으로 초기화

void dfs(int now) // now: 현재 탐색중인 노드 번호
{
    cout << now;
    for (int i = 0; i < 6; i++)
    {
        if (map[now][i] == 0)
            continue;
        dfs(i);
    }
}

int main()
{
    dfs(0);

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 트리(사이클x)
// DFS

vector<vector<int>> v(6);
char path[10];

void dfs(int lev, int now) // now: 현재 탐색중인 노드 번호
{
    cout << (char)('A' + now);

    for (int i = 0; i < v[now].size(); i++)
    {
        int next = v[now][i]; // 현재 노드에 연결 돼 있는 노드
        path[lev + 1] = 'A' + next;
        dfs(lev + 1, next);
        path[lev + 1] = 0;
    }
}

int main()
{
    v[0] = {1, 2};
    v[1] = {3};
    v[2] = {4, 5};

    path[0] = 'A'; // 시작점 넣어주기
    dfs(0, 0);

    return 0;
}
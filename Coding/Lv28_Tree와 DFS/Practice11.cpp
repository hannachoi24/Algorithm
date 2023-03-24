#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 트리(사이클x)
// DFS

string name = "ABTQVX";
vector<vector<int>> v(6);

void dfs(int now) // now: 현재 탐색중인 노드 번호
{
    cout << name[now];

    for (int i = 0; i < v[now].size(); i++)
    {
        int next = v[now][i];
        dfs(next);
    }
}

int main()
{
    v[0] = {1, 2, 3};
    v[1] = {4, 5};

    dfs(0);

    return 0;
}
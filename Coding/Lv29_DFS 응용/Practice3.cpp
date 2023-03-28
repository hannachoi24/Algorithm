#include <iostream>
#include <vector>
using namespace std;

// 한 번 방문한 곳 재방문 하지 않도록 구현 (인접리스트 버전)

bool visited[4] = {false};
vector<vector<int>> v(4);

void dfs(int now)
{
    cout << now;
    for (int i = 0; i < v[now].size(); i++)
    {
        int next = v[now][i];

        if (visited[next] == true)
            continue;
        visited[next] = true;
        dfs(next);
    }
}

int main()
{
    v[0] = {1, 3};
    v[1] = {2};
    v[2] = {0, 3};
    v[3] = {2};

    visited[0] = true; // 시작점 미리 방문체크

    dfs(0);

    return 0;
}
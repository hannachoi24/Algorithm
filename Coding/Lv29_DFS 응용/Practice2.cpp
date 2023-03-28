#include <iostream>
using namespace std;

// 한 번 방문한 곳 재방문 하지 않도록 구현 (인접행렬 버전)

bool visited[4] = {false};
int map[4][4] = {
    0, 1, 0, 1,
    0, 0, 1, 0,
    1, 0, 0, 1,
    0, 0, 1, 0};

void dfs(int now)
{
    cout << now;

    for (int i = 0; i < 4; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            if (map[now][i] == 0)
                continue;
            dfs(i);
        }
    }
}

int main()
{
    visited[0] = true; // 시작점 미리 방문체크
    dfs(0);
    return 0;
}
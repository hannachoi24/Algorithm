#include <iostream>
#include <string>
using namespace std;

// 인접행렬 장점: 초기화 간편
// 인접리스트 장점: 메모리 아끼고, 성능도 조금 더 빠름

// vector<vector<int>> alist(6); <- 인접리스트 방식

string name = "KGZHIR";
int map[6][6] = {
    0, 1, 1, 0, 0, 0,
    0, 0, 0, 1, 1, 0,
    0, 0, 0, 0, 0, 1};

void dfs(int now)
{
    cout << name[now];

    for (int i = 0; i < 6; i++)
    {
        if (map[now][i] == 0)
            continue;
        dfs(i);
    }
}

// 인접리스트 방식
// void dfs2(int now) {
//     cout << name[now];
//     for (int i = 0; i < alist[now].size(); i++) {
//         int next = alist[now][i];
//         dfs2(next);
//     }
// }

int main()
{
    dfs(0);

    // alist[0] = {1, 2};
    // alist[1] = {3, 4};
    // alist[2] = {5};

    return 0;
}
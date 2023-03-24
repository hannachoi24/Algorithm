#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 이진트리(사이클x)
// DFS

char vect[100] = {0, 'A', 'B', 'T', 'R', 'S', 'V'};

void dfs(int now)
{
    if (vect[now] == 0) // 연결된 노드가 없으면 리턴
        return;

    cout << vect[now];
    dfs(now * 2);     // 왼쪽 자식
    dfs(now * 2 + 1); // 오른쪽 자식
}

int main()
{
    dfs(1);

    return 0;
}
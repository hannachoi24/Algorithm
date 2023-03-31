#include <iostream>
#include <queue>
#include <string>
using namespace std;

// 모든 노드 1회씩 탐색은 DFS, BFS 모두 가능
// 모든 경로는 DFS 사용!
// 최소 경로는 BFS 사용!

string name = "ABCDE";

int map[5][5] = {
    0, 1, 1, 0, 0,
    1, 0, 1, 0, 0,
    1, 1, 0, 1, 0,
    0, 0, 1, 0, 1,
    0, 0, 0, 1, 0};

void bfs(int start)
{
    queue<char> q;
    bool visited[5] = {false};

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int now = q.front();
        cout << name[now];
        q.pop();

        for (int i = 0; i < 5; i++)
        {
            if (visited[i] == true)
                continue;
            if (map[now][i] == 0)
                continue;

            visited[i] = true;

            q.push(i);
        }
    }
}

int main()
{
    bfs(0);

    return 0;
}
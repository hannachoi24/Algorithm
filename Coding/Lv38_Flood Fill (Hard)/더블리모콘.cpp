#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// 더블 리모콘

bool visited[1000];

queue<pair<int, int>> q; // (현재 채널, 버튼 제어 횟수)를 저장하는 큐

int bfs(int start, int dest)
{
    q.push({start, 0});
    visited[start] = true;

    while (!q.empty())
    {
        int cur = q.front().first;  // 현재 채널
        int cnt = q.front().second; // 버튼 제어 횟수
        q.pop();

        // 목표 채널에 도달한 경우 버튼 제어 횟수 반환
        if (cur == dest)
            return cnt;

        // 현재 채널에서 +1, -1, x2, /2 버튼으로 이동한 결과를 큐에 삽입
        int next[] = {cur + 1, cur - 1, cur * 2, cur / 2};
        for (int i = 0; i < 4; i++)
        {
            if (next[i] >= 0 && next[i] <= 100000 && !visited[next[i]])
            {
                q.push({next[i], cnt + 1});
                visited[next[i]] = true;
            }
        }
    }
    return 0;
}

int main()
{
    int start, dest;
    cin >> start >> dest;

    memset(visited, false, sizeof(visited)); // visited 배열 초기화
    cout << bfs(start, dest);

    return 0;
}
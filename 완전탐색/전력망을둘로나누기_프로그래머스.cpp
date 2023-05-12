#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define MAX 101

using namespace std;

int cnt = 0;
vector<int> info[MAX];

void bfs(int v1, int v2)
{
    queue<int> q;
    vector<bool> visited(MAX);

    q.push(v1);
    visited[v1] = true;
    visited[v2] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int i = 0; i < info[node].size(); i++)
        {
            int next_node = info[node][i];

            if (visited[next_node])
                continue;

            cnt++;
            q.push(next_node);
            visited[next_node] = true;
        }
    }
}

// 초기화(연결)
int solution(int n, vector<vector<int>> wires)
{
    int answer = MAX;

    for (auto wire : wires)
    {
        info[wire[0]].push_back(wire[1]);
        info[wire[1]].push_back(wire[0]);
    }

    for (auto wire : wires)
    {
        cnt = 1;
        int v1 = wire[0];
        int v2 = wire[1];

        bfs(v1, v2);

        answer = min(answer, abs(2 * cnt - n));
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> wires = {{1, 3},
                                 {2, 3},
                                 {3, 4},
                                 {4, 5},
                                 {4, 6},
                                 {4, 7},
                                 {7, 8},
                                 {7, 9}};

    cout << solution(9, wires) << '\n';

    return 0;
}

/*
1. 송전탑의 전선 정보를 info 벡터에 저장

2. 전선을 하나씩 끊어가면서 bfs 수행하여 하나의 전력망의 송전탑 개수를 계산

끊은 전선의 양쪽 송전탑은 방문 체크 visited[v1] = true; visited[v2] = true;
방문하지 않은 송전탑이면 cnt++

3. 두 전력망의 차이가 answer보다 작다면 answer 갱신
*/
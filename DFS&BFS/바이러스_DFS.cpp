#include <iostream>
#include <vector>

using namespace std;

vector<int> a[101]; // 인접 리스트
bool visited[101];
int cnt = 0;

void dfs(int x)
{
    // 현재 노드를 방문 처리
    visited[x] = true;

    // 현재 노드와 연결된 다른 노드를 재귀적으로 방문
    for (int i = 0; i < a[x].size(); i++)
    {
        int y = a[x][i];
        if (!visited[y])
        {
            dfs(y);
            cnt++;
        }
    }
}

int main()
{
    int n, m; // n: 노드 개수, m: 엣지 개수
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        // 노드 u에 연결된 노드 정보 저장
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    } // edge 연결해줬음
    dfs(1);
    cout << cnt << '\n';
}

// 연결된 애들끼리 감염되는데 1번을 통해서 바이러스에 걸리니까 DFS나 BFS를 반복문을 따로 할 필요 없이
// (전체 연결된 그래프를 찾는게아니라 1번이랑 연결된 그래프만 찾으면 되니까) 1번에서 호출하면 된다.
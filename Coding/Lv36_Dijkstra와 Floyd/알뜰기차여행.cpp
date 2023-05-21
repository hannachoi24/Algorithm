#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

const int INF = 21e8;

void dijkstra(vector<vector<pii>> &graph, int start, vector<int> &dist)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    // 시작점
    pq.push({0, start});
    dist[start] = 0;

    // BFS
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        // 1. 최신 데이터인지?
        if (dist[cur] < cost)
            continue;

        // 2. 큐 등록
        for (pii next : graph[cur])
        {
            int nextCost = cost + next.second;
            int neighbor = next.first;

            if (dist[neighbor] > nextCost)
            {
                dist[neighbor] = nextCost;
                pq.push({nextCost, neighbor});
            }
        }
    }
}

int main()
{
    int N, T; // N: 정점의 개수, T: 간선의 수
    cin >> N >> T;

    vector<vector<pii>> graph(N);
    for (int i = 0; i < T; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
    }

    vector<int> dist(N, INF);
    dijkstra(graph, 0, dist);

    if (dist[N - 1] == INF)
    {
        cout << "impossible" << '\n';
    }
    else
    {
        cout << dist[N - 1] << '\n';
    }

    return 0;
}

/* 또 다른 코드
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
    int to;
    int cost;
};

bool operator<(Edge left, Edge right) {
    if (left.cost < right.cost) return false;
    if (left.cost > right.cost) return true;
    if (left.to < right.to) return false;
    if (left.to > right.to) return true;
    return false;
}

int node, edge;
vector<Edge> v[100000];
int dist[100000];
int visited[100000];
priority_queue<Edge> pq;

void djikstra() {
    // 1. 시작 노드를 pq
    dist[0] = 0;
    pq.push({ 0, 0 });
    // 2. BFS
    while (!pq.empty()) {
        Edge nowedge = pq.top();
        pq.pop();
        int now = nowedge.to;
        if (visited[now] == 1) continue;
        visited[now] = 1;
        // 3. 인접 노드 체크
        for (int i = 0; i < v[now].size(); i++) {
            Edge nextedge = v[now][i];
            int next = nextedge.to;
            int cost = nextedge.cost;
            if (dist[next] < dist[now] + cost) continue;
            dist[next] = dist[now] + cost;
            pq.push({ next, dist[next] });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> node >> edge;
    for (int i = 0; i < edge; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back({ to, cost });
    }
    for (int i = 0; i < node; i++) {
        dist[i] = 2134567890;
    }
    djikstra();
    if (dist[node - 1] == 2134567890)
        cout << "impossible";
    else
        cout << dist[node - 1];
}
*/
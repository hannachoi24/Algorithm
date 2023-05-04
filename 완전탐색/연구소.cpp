#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int map[8][8];
int tmp[8][8];

struct Node
{
    int x, y;
};

int safe_cnt;

// 바이러스 퍼뜨리기
void bfs()
{
    int spread[8][8];
    memcpy(spread, tmp, sizeof(tmp));
    queue<Node> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (spread[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (spread[nx][ny] == 0) // 0이면 2로 바꿔서 바이러스 전염되게 함
            {
                spread[nx][ny] = 2;
                q.push({nx, ny}); // 바이러스 있으니까 큐에 푸시
            }
        }
    }

    // 안전 영역의 크기
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (spread[i][j] == 0)
            {
                cnt += 1;
            }
        }
    }
    safe_cnt = max(safe_cnt, cnt);
}

// 벽 세우기
void wall(int cnt)
{
    // 벽이 3개 세워졌을 때 바이러스 퍼뜨림(bfs 호출)
    if (cnt == 3)
    {
        bfs();
        return;
    }

    // 벽 세움
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tmp[i][j] == 0)
            {
                tmp[i][j] = 1;
                wall(cnt + 1);
                // 기존의 1을 0으로 바꿔줌
                tmp[i][j] = 0;
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    // 0인 부분은 모두 벽을 세워야 함
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
            {
                memcpy(tmp, map, sizeof(map));
                tmp[i][j] = 1;
                wall(1);
                tmp[i][j] = 0;
            }
        }
    }

    cout << safe_cnt;

    return 0;
}

/* 또 다른 코드
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int N, M;
int board[10][10];
int test[10][10];
vector<pair<int, int> > virus;
int ans = 0;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void cal(){
    int res = 0;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            if (test[i][j] == 0) res++;
    ans = max(ans, res);
}

void bfs(){
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            test[i][j] = board[i][j];
    int vis[10][10];
    for (int i=0; i<10; i++) fill(vis[i], vis[i]+10, false);
    queue<pair<int, int> > Q;
    for (auto &v: virus){
        Q.push(v);
        vis[v.X][v.Y] = true;
    }
    while (!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir<4; dir++){
            int nx = cur.X+ dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx<0 || nx >= N || ny <0 || ny >= M) continue;
            if (test[nx][ny] != 0) continue;
            if (vis[nx][ny]) continue;

            test[nx][ny] = 2;
            vis[nx][ny] = true;
            Q.push(make_pair(nx, ny));
        }
    }

    cal();
}

void dfs(int L){
    if (L == 3){
        bfs();
        return;
    }

    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++){
            if (board[i][j] != 0) continue;
            board[i][j] = 1;
            dfs(L+1);
            board[i][j] = 0;
        }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++){
            cin >> board[i][j];
            if (board[i][j] == 2) {
                virus.push_back(make_pair(i, j));
            }
        }

    dfs(0);
    cout << ans;

    return 0;
}
*/
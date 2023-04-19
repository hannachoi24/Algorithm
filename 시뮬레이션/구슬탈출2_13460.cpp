#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int Rx, Ry; // 빨간공의 좌표
    int Bx, By; // 파란공의 좌표
    int cnt;    // 움직인 수
};

char map[11][11];
bool visit[11][11][11][11];
int n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void move(int &x, int &y, int &distance, int &i)
{
    while (map[x + dx[i]][y + dy[i]] != '#' && map[x][y] != 'O')
    {
        x += dx[i];    // x좌표 이동
        y += dy[i];    // y좌표 이동
        distance += 1; // 공이 움직인 거리
    }
}

void bfs(int Rx, int Ry, int Bx, int By)
{
    queue<Node> q;
    q.push({Rx, Ry, Bx, By, 0});
    visit[Rx][Ry][Bx][By] = true;

    while (!q.empty())
    {
        int rx = q.front().Rx;
        int ry = q.front().Ry;
        int bx = q.front().Bx;
        int by = q.front().By;
        int count = q.front().cnt;
        q.pop();

        if (count >= 10) // 범위 벗어나면 종료
            break;

        for (int i = 0; i < 4; i++)
        {
            int nRx = rx, nRy = ry;
            int nBx = bx, nBy = by;
            int rc = 0, bc = 0, nCnt = count + 1;

            move(nRx, nRy, rc, i); // 빨간 공 이동
            move(nBx, nBy, bc, i); // 파란 공 이동

            if (map[nBx][nBy] == 'O') // 파란 구슬은 구멍에 들어갈 수 없음
                continue;

            if (map[nRx][nRy] == 'O') // 빨간 구슬이 구멍에 들어갔을 때 카운트
            {
                cout << nCnt;
                return;
            }

            // 파란 구슬과 빨간 구슬이 같은 위치
            // -> 빨간 공과 파란 공이 움직인 거리를 확인해 움직인 거리가 큰 공을 한 칸 뒤로 이동시켜 공이 겹치는 경우를 고려
            if (nRx == nBx && nRy == nBy)
            {
                if (rc > bc)
                    nRx -= dx[i], nRy -= dy[i]; // 빨간공을 뒤로
                else
                    nBx -= dx[i], nBy -= dy[i]; // 파란공을 뒤로
            }

            if (visit[nRx][nRy][nBx][nBy])
                continue;
            visit[nRx][nRy][nBx][nBy] = true;
            q.push({nRx, nRy, nBx, nBy, nCnt});
        }
    }
    cout << -1; // 움직인 거리의 수가 10 이상인 경우 -1을 출력
}

int main()
{
    cin >> n >> m;
    int Rx = 0, Ry = 0, Bx = 0, By = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 'R') // 빨간공 위치 저장
            {
                Rx = i, Ry = j;
            }
            if (map[i][j] == 'B') // 파란공 위치 저장
            {
                Bx = i, By = j;
            }
        }
    }

    bfs(Rx, Ry, Bx, By);

    return 0;
}
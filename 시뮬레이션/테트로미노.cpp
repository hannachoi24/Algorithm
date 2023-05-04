#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int board[501][501];
bool visit[501][501];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int max_sum = -1;

void solve(int x, int y, int sum, int cnt)
{
    // 테트로미노 완성 시 수들의 합 계산
    if (cnt == 4)
    {
        max_sum = max(max_sum, sum);
        return;
    }

    // 상하좌우 탐색
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;

        if (!visit[nx][ny])
        {
            // 보라색(ㅗ) 테트로미노 만들기 위해 2번째 칸에서 탐색 한번 더 진행
            if (cnt == 2)
            {
                visit[nx][ny] = true;
                solve(x, y, sum + board[nx][ny], cnt + 1);
                visit[nx][ny] = false;
            }

            visit[nx][ny] = true;
            solve(nx, ny, sum + board[nx][ny], cnt + 1);
            visit[nx][ny] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    memset(board, 0, sizeof(board));
    memset(visit, false, sizeof(visit));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    // 전체 탐색(dfs)
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visit[i][j] = true;
            solve(i, j, board[i][j], 1);
            visit[i][j] = false;
        }
    }

    cout << max_sum << "\n";
    return 0;
}

/*
 * 탐색의 2번째 칸에서
 * 양쪽으로 하나씩 움직여야 만들 수 있는 형태이기 때문에 상하좌우 탐색으로는 결과를 구할 수 없다.
 * 따라서 탐색 시 2번째 칸 일때, 3번째 탐색을 시작하는 위치를 3번째 탐색 위치로 하는 것이 아니라
 * 2번째 칸에서 다시 한번 탐색하도록 하는 경우를 추가해주면 구할 수 있다.
 */

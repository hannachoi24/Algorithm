#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int arr[301][301]; // arr은 출발지로부터 해당 좌표(i, j)까지의 최소 이동 횟수를 담아 놓은 것
bool visited[301][301];

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int I; //체스판의 한 변의 길이
queue<pair<int, int>> q;
int srcX, srcY, dstX, dstY; // src: 나이트가 현재 있는 칸, dst: 나이트가 이동하려고 하는 칸

void bfs(int a, int b)
{
    q.push(make_pair(a, b));
    visited[a][b] = true;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == dstX && y == dstY)
        {
            cout << arr[x][y] << '\n';

            while (!q.empty())
            {
                q.pop();
            }
            break;
        }

        for (int i = 0; i < 8; i++)
        { // 한 칸씩 이동
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < I && ny >= 0 && ny < I)
            {
                if (visited[nx][ny] == false) // 이동한 곳이 방문되지 않은 곳이라면,
                {
                    visited[nx][ny] = true; // 방문 처리
                    arr[nx][ny] = arr[x][y] + 1;
                    q.push(make_pair(nx, ny)); // 이동 된 위치 넣어줌
                }
            }
        }
    }
}

int main()
{
    int TC; // 테스트 케이스
    cin >> TC;

    for (int i = 0; i < TC; i++)
    {
        cin >> I;
        cin >> srcX >> srcY >> dstX >> dstY;
        bfs(srcX, srcY);
        memset(arr, 0, sizeof(arr));
        memset(visited, false, sizeof(visited));
    }
    return 0;
}

// <풀이>
// dfs가 아닌 bfs를 이용한다.
// bfs를 활용했을 때 목적지에 도착했을 당시 최소 이동 횟수이기 때문이다. dfs는 목적지에 도착했을 때 최소 이동 횟수가 아니기 때문이다.
// 최소 이동 횟수를 구할 때는 bfs로 구해야 할 것 같다.
// 배열 arr은 출발지로부터 해당 좌표(i, j)까지의 최소 이동 횟수를 담아 놓은 것이다.
// bfs방식으로 큐를 이용하여 출발 좌표부터 탐색을 시작하고 출발지 좌표가 나오면 그 때 arr배열의 값을 출력해주고 탈출하면 된다.
// 테스트케이스도 입력을 받으니 테스트케이스를 하나 실행할때 마다 배열들을 초기화시켜준다.

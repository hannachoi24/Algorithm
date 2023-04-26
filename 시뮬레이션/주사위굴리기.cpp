#include <iostream>
#include <vector>

using namespace std;

int n, m, x, y, k;
int map[21][21];
int order[1001];
vector<int> dice(7); // index 1 윗면, 2 북쪽면, 3 동쪽면, 4 서쪽면, 5 남쪽면, 6 아랫면

// 제자리, 동, 서, 북, 남
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

// 입력
void input()
{
    cin >> n >> m >> x >> y >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < k; i++)
    {
        cin >> order[i];
    }
}

// 동쪽으로 굴리기
void East()
{
    dice = {0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3]};
}

// 서쪽으로 굴리기
void West()
{
    dice = {0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4]};
}

// 북쪽으로 굴리기
void North()
{
    dice = {0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2]};
}

// 남쪽으로 굴리기
void South()
{
    dice = {0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5]};
}

void roll(int order)
{
    switch (order)
    {
    case 1:
        East();
        break;
    case 2:
        West();
        break;
    case 3:
        North();
        break;
    case 4:
        South();
        break;
    default:
        break;
    }
}

void solve()
{
    for (int i = 0; i < k; i++)
    {
        int nx = dx[order[i]];
        int ny = dy[order[i]];

        if (x + nx < 0 || n <= x + nx || y + ny < 0 || m <= y + ny)
            continue;

        // 주사위 위치하는 칸 이동
        x += nx;
        y += ny;

        // 명령에 따라 주사위 굴리기
        roll(order[i]);

        cout << dice[1] << '\n'; // 윗면 출력

        // 도착한 보드 칸이 0 이라면
        if (map[x][y] == 0)
            map[x][y] = dice[6]; // 주사위 아랫면 숫자를 위치한 칸에 복사
        else
        {
            dice[6] = map[x][y];
            map[x][y] = 0;
        }
    }
}

int main()
{
    input();
    solve();

    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, L; // N: 크기, L: 경사로의 길이
vector<vector<int>> map;
int cnt = 0;

// 한 줄이 경사로인지 확인 d = 0 이면 열검사, d = 1 이면 행검사
bool canGo(int x, int y, int d)
{
    vector<int> height(N);
    vector<bool> visit(N, false); // 경사로가 이미 놓여있는지 체크

    // 알아보기 쉽게 height 배열에 옮기기
    // 2차원으로 돼 있는 지도에서 길 하나만 체크하면 되기 때문에 1차원 배열에 옮기기
    for (int i = 0; i < N; i++)
    {
        height[i] = (d == 0) ? map[x][y + i] : map[x + i][y];
    }

    for (int i = 0; i < N - 1; i++)
    {
        // 높이가 같으면 패스(경사로 놓을 필요x)
        if (height[i] == height[i + 1])
        {
            continue;
        }

        // 높이 차이가 2 이상이면 경사로 놓을 수 없음
        if (abs(height[i] - height[i + 1]) > 1)
        {
            return false;
        }

        // 내려가야되는 경우
        if (height[i] - 1 == height[i + 1]) // ex) 3 2
        {
            // 다음 인덱스부터 앞으로 길이 L 만큼
            for (int j = i + 1; j <= i + L; j++)
            {
                // j가 범위를 벗어나거나 높이가 다르거나 이미 경사로가 있는 경우
                if (j >= N || height[i + 1] != height[j] || visit[j])
                {
                    return false;
                }
                visit[j] = true;
            }
        }

        // 올라가야되는 경우
        else if (height[i] + 1 == height[i + 1])
        {
            // 현재 인덱스부터 뒤로 길이 L 만큼
            for (int j = i; j > i - L; j--)
            {
                if (j < 0 || height[i] != height[j] || visit[j])
                {
                    return false;
                }
                visit[j] = true;
            }
        }
    }

    return true; // 조건에 걸리지 않고 무사히 for문을 돌면 끝까지 도착했다는 뜻이므로 true를 return
}

int main()
{
    cin >> N >> L;

    map.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    // x 가 0 이며 세로로 가는 길 또는 y 가 0 이며 가로로 가는 길 모두 확인하며 카운트
    for (int i = 0; i < N; i++)
    {
        if (canGo(i, 0, 0))
            cnt++;

        if (canGo(0, i, 1))
            cnt++;
    }

    cout << cnt << '\n';

    return 0;
}
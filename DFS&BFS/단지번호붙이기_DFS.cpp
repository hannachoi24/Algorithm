#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

string arr[25]; // 1: 집이 있는 곳, 0: 집이 없는 곳 확인하기 위함
bool visited[25][25] = {
    false,
};
int N;            // 지도의 크기
int cnt;          // 각 단지 내 집 수
vector<int> home; // 단지 내 집 수 저장용 벡터

void dfs(int i, int j)
{
    // 현재 노드를 방문 처리
    visited[i][j] = true;
    cnt++;

    for (int k = 0; k < 4; k++)
    {
        int newY = i + dy[k]; // 상, 하, 좌, 우 로 1칸씩 이동
        int newX = j + dx[k];

        if (0 <= newX && newX < N && 0 <= newY && newY < N)
            if (arr[newY][newX] == '1' && !visited[newY][newX])
                dfs(newY, newX);
    }
}

int main()
{
    cin >> N; // 지도의 크기

    for (int i = 0; i < N; i++)
        cin >> arr[i]; // N개의 자료(0혹은 1)

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == '1' && !visited[i][j])
            {
                cnt = 0;
                dfs(i, j);
                home.push_back(cnt);
            }
        }
    }

    sort(home.begin(), home.end());

    cout << home.size() << endl; // 총 단지 수
    for (int i = 0; i < home.size(); i++)
        cout << home[i] << endl; // 각 단지내 집의 수

    return 0;
}

// 단순한 DFS 문제다. 지도의 모든 곳을 탐색하면서 아파트 단지가 있다면 그 자리에서 DFS를 실행한다.
// 연결된 단지들을 별도로 세어야 하므로 연결요소의 개념도 알아야 풀 수 있다.
// DFS를 도는 지점에서 상하좌우를 체크해서 아파트단지가 있다면 재귀적으로 DFS를 실행한다.
// 연결요소 내부의 갯수는 DFS 시작 시 0으로 설정하고 재귀함수 내에서 수를 올려준다.
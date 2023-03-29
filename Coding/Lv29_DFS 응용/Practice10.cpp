#include <iostream>
using namespace std;

// 가장 비싼/ 싼 비용 출력

int map[6][6] = {
    0, 2, 6, 3, 0, 0,
    2, 0, 7, 4, 0, 0,
    6, 7, 0, 0, 0, 0,
    3, 4, 2, 0, 0, 0,
    0, 0, 1, 0, 0, 7,
    0, 0, 0, 0, 0, 0};

bool visited[6] = {false};

int maxi = -21e8;
int mini = 21e8;
int a, b;

void dfs(int now, int sum)
{
    if (now == b)
    {
        if (sum > maxi)
        {
            maxi = sum;
        }

        if (sum < mini)
        {
            mini = sum;
        }
        return;
    }

    for (int i = 0; i < 6; i++)
    {
        if (map[now][i] == 0)
            continue;
        if (visited[i] == true)
            continue;
        visited[i] = true;
        dfs(i, sum + map[now][i]);
        visited[i] = false;
    }
}

int main()
{
    cin >> a >> b;
    dfs(a, 0);
    cout << maxi << '\n';
    cout << mini << '\n';
    return 0;
}
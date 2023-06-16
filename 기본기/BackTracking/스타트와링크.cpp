#include <iostream>
using namespace std;

int n;
int map[21][21];
bool check[22];
int mini = 21e8;

void dfs(int x, int next) // x는 카운트 수, pos는 다음 값
{
    if (x == n / 2) // 카운트수가 정원의 n/2이 됐을 때 능력치합 계산
    {
        int start, link;
        start = 0;
        link = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (check[i] == true && check[j] == true)
                    start += map[i][j];
                if (check[i] == false && check[j] == false)
                    link += map[i][j];
            }
        }

        int diff = abs(start - link);
        if (diff < mini)
        {
            mini = diff;
            return;
        }
    }

    for (int i = next; i < n; i++)
    {
        check[i] = true;
        dfs(x + 1, i + 1);
        check[i] = false;
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    dfs(0, 1); // 카운트 0회부터 숫자는 1부터 시작

    cout << mini;

    return 0;
}
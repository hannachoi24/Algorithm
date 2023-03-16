#include <iostream>
using namespace std;

// 중복 순열
// 주사위 n개를 굴려 같은 눈금이 나오지 않도록하고 n개의 눈금합이 10보다 같거나 크면 안되는 모든 눈금 출력

char path[10];
bool visit[6];
int n;

void run(int lev, int n, int sum)
{
    if (sum >= 10) // 가지치기1
        return;

    if (lev == n)
    {
        cout << path << '\n';
        return;
    }

    for (int i = 1; i <= 6; i++)
    {
        // if (sum + i >= 10) continue; 가지치기2
        if (visit[i] == true)
            continue;
        visit[i] = true;
        path[lev] = '0' + i;
        run(lev + 1, n, sum + i);
        path[lev] = 0;
        visit[i] = false;
    }
}

int main()
{
    cin >> n;

    run(0, n, 0);

    return 0;
}
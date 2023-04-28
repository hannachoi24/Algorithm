#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> q;

int result[1500];

int main()
{
    q.push(1);

    int cnt = 0;
    int now = 0;
    int old = -1;

    // 1 ~ 1300 등까지 정답 미리 구해두기
    while (1)
    {
        now = q.top();
        q.pop();
        if (old == now)
            continue;
        old = now;

        cnt++;
        result[cnt] = now;
        if (cnt == 1300)
            break;

        q.push(now * 2);
        q.push(now * 3);
        q.push(now * 5);
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tar;
        cin >> tar;
        cout << result[tar] << " ";
    }

    return 0;
}
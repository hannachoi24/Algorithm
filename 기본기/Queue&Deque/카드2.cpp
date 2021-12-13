#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    queue<int> q;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    while (q.size() > 1)
    {
        q.pop();           // 제일 위에 카드 버림
        q.push(q.front()); // 그 다음 위에거를 제일 밑으로 넣어준다.
        q.pop();
    }

    cout << q.front() << endl;

    return 0;
}
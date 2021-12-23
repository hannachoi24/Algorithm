#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

int n;
priority_queue<int> pq;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    while (n--)
    { // 연산의 개수 만큼 반복
        int x;
        cin >> x;

        if (x == 0)
        {
            if (pq.empty())
            {
                cout << "0\n";
                continue;
            }

            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }

        else
        {
            pq.push(x);
        }
    }

    return 0;
}

/* priority_queue , ‘우선 순위 큐’
1. 큐와 마찬가지로 FIFO(First in, First out)의 성질을 가지고 있다.
2. 하지만 큐와 다르게 자동으로 내림차순 정렬되어 아이템이 삽입된다.
그리하여 priority_queue에는 2 -> 1 -> 3 순서로 삽입해도 3 -> 2 -> 1 순서로 쌓이게 된다.
즉, priority_queue에 삽입 후 맨 위의 값만 출력해주며 pop()만 해주어도 큰 순서대로 출력이 가능하다는 뜻이다. */
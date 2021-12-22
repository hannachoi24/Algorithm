#include <iostream>
#include <algorithm>
using namespace std;

int n, k;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;

    int start = 1, end = k, mid;
    int res = 0;

    for (;;)
    {
        if (start > end)
            break;

        mid = (start + end) / 2;

        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cnt += min(n, mid / i);
        }

        if (cnt >= k)
        {
            res = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    cout << res << '\n';

    return 0;
}

/*그리고 여기에서 k = 11 일 때, 즉 B[11] 을 찾는 경우를 생각해보자.

우리가 찾는 11번째의 숫자를 S 이라고 한다면, 다음과 같이 접근해야 한다.

"전체 숫자 중에서, S보다 작거나 같은 숫자의 개수가 11개보다 작으면 안된다!"

→ 만약 그렇다면, 찾는 숫자의 범위를 큰 쪽으로 옮겨야 한다.

 
그렇다면, S보다 작거나 같은 숫자의 개수는 어떻게 구할까?

이 계산을 구현하는 것이 이 알고리즘의 핵심이 되겠다.

만약 S를 5라고 가정하고, 5보다 작거나 같은 개수를 찾는 경우를 생각해보자.
5보다 작거나 같은 개수의 합은 10개이다.

잘 생각해보면, 각 행에서의 S보다 작거나 같은 숫자의 개수는

min(S / i, N) 임을 알 수 있다.

왜냐하면, 각 행은

i * 1,   i * 2,   i * 3,   i * 4,   .....   , i * j 이기 때문에,

S를 i로 나눈 값에 나머지를 버린 값이 그 행에서 S보다 작거나 같은 개수가 되기 때문이다.

 
그러므로, 우리는 S를 찾기 위해

초기값 = 1,   마지막 값 = k,   중간 값 = (1 + k) / 2

로 시작하는 이분 탐색을 적용하면 된다.

여기에서 마지막 값이 k인 이유는

"B[k] 의 값은 k보다 작거나 같기" 때문이다. */
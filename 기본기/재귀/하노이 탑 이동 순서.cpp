#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int start, int mid, int end, int n)
{
    if (n == 1)
    {
        cout << start << " " << end << "\n";
    }
    else
    {
        hanoi(start, end, mid, n - 1);
        cout << start << " " << end << '\n';
        hanoi(mid, start, end, n - 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cout << (int)pow(2, n) - 1 << '\n'; // pow 함수 앞에 (int)를 적지 않으면, 입력 최대가 20인 pow 함수의 특성상 오차가 커지게됨.
    hanoi(1, 2, 3, n);
}

/* n개의 원판을 첫번째 막대에서 세번째 막대로 옮기는 기본적인 방법은

    n -1개의 원판을 첫번째에서 두번째로,

    마지막 원판을 첫번째에서 세번째로,

    n - 1개의 원판을 두번째에서 세번째로 옮기는 것이다.

    이를 바탕으로 재귀 함수를 작성하였다.

    또한, 옮긴 횟수는 출력하는 한줄마다 count하면 좋겠지만,

    횟수를 먼저 출력해야하므로 하노이탑 최소 이동횟수 2 ^ n - 1을 계산하여 출력 */
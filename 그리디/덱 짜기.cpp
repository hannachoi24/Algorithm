#include <iostream>

using namespace std;

// 레전드 오브 트럼프는 빨간 카드 3장과 검은 카드 2장을 하나의 덱으로 만들어 싸우는 카드 게임입니다.
// 엘리스 토끼는 빨간 카드 A 장과 검은 카드 B 장으로 덱을 만들려고 합니다.
// 그런데 너무 좋은 카드들이 많아져서 이번 대회에서는 k 장을 무조건 빼야 한다는 룰이 생겼습니다.

int main()
{

    int a, b, k;
    cin >> a >> b >> k;

    int ans = 0;

    while (a >= 3 && b >= 2 && (a + b) >= k + 5)
    {
        a -= 3;
        b -= 2;
        ans += 1;
    }

    cout << ans << '\n';
    return 0;
}

#include <iostream>

using namespace std;

bool Hansu(int a)
{
    if (a < 100)
        return true;
    int a1, a2, a3;
    a3 = a / 100;      // 100의 자리
    a2 = a % 100 / 10; // 10의 자리
    a1 = a % 10;       // 1의 자리
    if (a3 - a2 == a2 - a1)
        return true;
    return false;
}

int main(void)
{
    int n, count = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (Hansu(i))
            count++;
    }
    cout << count;
}

/* 모든 두 자릿수는 각 자리수가 등차수열을 이룬다고 볼 수 있으므로 한수이지만 예제 1에서는 110을 입력받고 99를 출력하므로 
1부터 99가 모두 한수로 인정됨을 알 수 있다.

그래서 Hansu 함수에 보면 100미만 자연수는 모두 true를 출력하여 count를 증가시키도록 구현한다.

세 자릿수는 a3에 백의 자리, a2에 십의 자리, a1에 1의 자리를 각각 대입하였고,

 a3-a2, a2-a1은 공차이므로 그 값이 서로 같아야 한다.

같지 않으면 등차수열에 해당하지 않으므로 if 문의 조건을 만족하지 못하고 false를 리턴한다.

마지막엔 count를 출력하면 한수의 개수가 출력된다. */
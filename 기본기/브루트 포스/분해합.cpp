#include <iostream>
using namespace std;

int solution(int n)
{
    int sum = n;
    while (n)
    {
        sum = sum + n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    int N;
    cin >> N;

    for (int i = 1; i < N; i++) // 출력은 입력보다 무조건 작을 것이 분명함. 그러므로 for문을 통해 "1~입력" 까지 범위 설정.
    {
        int sum = solution(i);
        if (sum == N) // 분해합(각 자리수의 합과 자기 자신을 더한 값)이 입력과 동일할 경우 출력.
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
}
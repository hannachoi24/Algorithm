#include <iostream>
using namespace std;

/* 기약 분수 형태로 출력하는 것만 신경 쓰면 되는 문제이다.

기약 분수로 만들기 위해서는 최대공약수로 나눠주면 된다!

결국 최대공약수를 구하는 문제이다! 유클리드 알고리즘을 알고 있다면 쉽게 풀리는 문제*/

int arr[100];

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++)
    { // 기약분수 = 기준이 되는 첫번째 항을 최대공약수로 나눈 값 / 해당 반지름을 최대공약수로 나눈 값
        int temp = gcd(arr[0], arr[i]);
        cout << arr[0] / temp << "/" << arr[i] / temp << endl;
    }
}
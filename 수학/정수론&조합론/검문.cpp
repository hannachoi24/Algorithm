#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int arr[101] = {
    0,
};
int sol[501] = {
    0,
};
int cnt = 0;

int gcd(int a, int b)
{
    if (a % b == 0)
    {
        return b;
    }
    return gcd(b, a % b);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    sort(arr, arr + n);

    int bm = arr[1] - arr[0];
    // arr[i]-arr[i-1] 의 최대공약수를 고른다.
    for (int i = 2; i < n; i++)
    {
        bm = gcd(bm, arr[i] - arr[i - 1]);
    };

    // 약수 구하는 가장 빠른 방법
    // 30의 약수를 구할때, 5가 약수인걸 알면 30/5 =6 을 알 수 있는것처럼, 짝을 바로 구해나간다.
    for (int i = 2; i * i <= bm; i++)
    {
        if (bm % i == 0)
        {
            sol[cnt++] = i;
            if (i * i != bm)
                sol[cnt++] = bm / i;
        }
    };
    // 위 i=2 로 진행하여, 1의 짝인 bm이 들어가지 못해 넣어줌
    sol[cnt++] = bm;

    // 오름차순이므로, 정렬 후 출력하기
    sort(sol, sol + cnt);
    for (int i = 0; i < cnt; i++)
    {
        printf("%d ", sol[i]);
    }

    return 0;
}
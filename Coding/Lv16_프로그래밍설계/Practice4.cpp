#include <iostream>

using namespace std;

/* 행은 합 연산을 수행해서 각 행에 나온 연산 결과 값들 중 큰 값 도출, 열은 곱 연산 수행해서 각 열에 나온 결과 값들 중 큰 값 도출 
    두 개의 결과 값 중 큰 값을 출력 */

int map[2][4]{
    1, 5, 4, 2,
    6, 6, 5, 1};

int getSum(int a, int b, int c, int d)
{
    return a + b + c + d;
}

int getMul(int a, int b)
{
    return a * b;
}

int getMax(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{

    // 1. 행 연산
    int d1 = getSum(map[0][0], map[0][1], map[0][2], map[0][3]);
    int d2 = getSum(map[1][0], map[1][1], map[1][2], map[1][3]);
    int boss1 = getMax(d1, d2);

    // 2. 열 연산
    int boss2 = -99999;

    for (int i = 0; i < 4; i++)
    {
        int temp = getMul(map[i][0], map[i][1]);
        if (boss2 < temp)
            boss2 = temp;
    }

    // 3. 최종 결과 출력
    int result = getMax(boss1, boss2);

    cout << result;

    return 0;
}
#include <iostream>
using namespace std;

/*
우선순위가 높은 것이 왼쪽에 등장해야함
isCompare(A, B)가 1을 리턴하면
A가 더 우선순위가 높다는 뜻
만약 A, B 중에 우선순위가 B가 더 높으면 swap
*/

int isCompare(int a, int b)
{
    // a가 우선순위가 더 높으면 1 리턴
    // a가 우선순위가 낮으면 0 리턴

    // 짝수 우선
    if (a % 2 == 0 && b % 2 == 1)
        return 1;
    if (a % 2 == 1 && b % 2 == 0)
        return 0;

    // 작은 수 우선
    if (a < b)
        return 1;
    return 0;
}

int main()
{
    int n = 7;
    int arr[7] = {4, 3, 2, 1, 6, 4, 5};
    int result[7] = {0};

    for (int i = 0; i < n; i++)
    {
        // 1. 맨 뒤에 넣기
        result[i] = arr[i];

        // 2. 정렬 수행
        for (int j = i; j > 0; j--)
        {
            if (isCompare(result[j - 1], result[j]) == 0)
            {
                swap(result[j - 1], result[j]);
            }
            else
                break; // 내 자리
        }
    }

    for (int i = 0; i < 7; i++)
    {
        cout << result[i] << '\n';
    }

    return 0;
}
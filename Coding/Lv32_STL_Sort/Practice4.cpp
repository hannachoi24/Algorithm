#include <iostream>
#include <algorithm>
using namespace std;

int arr[5] = {4, 3, 1, 6, 2};

int cmp(int a, int b)
{
    // 큰 수가 우선 순위가 높으면 내림 차순
    if (a > b)
        return 1;

    return 0;
}

int main()
{
    // 1. 오름차순
    sort(arr, arr + 5);

    // 2. 내림차순
    sort(arr, arr + 5, greater<int>());

    // 3. 다중조건
    sort(arr, arr + 5, cmp);

    return 0;
}
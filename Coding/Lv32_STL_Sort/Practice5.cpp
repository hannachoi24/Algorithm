#include <iostream>
#include <algorithm>
using namespace std;

int arr[5] = {4, 3, 1, 6, 2};

int cmp(int a, int b)
{
    // 1. 짝수 우선
    if (a % 2 == 0 && b % 2 == 1)
        return 1;
    if (a % 2 == 1 && b % 2 == 0)
        return 0;

    // 2. 작은 수 우선
    return a < b;
}

int main()
{
    // 다중조건
    sort(arr, arr + 5, cmp);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i];
    }

    return 0;
}
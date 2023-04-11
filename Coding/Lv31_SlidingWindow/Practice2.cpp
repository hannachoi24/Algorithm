#include <iostream>
using namespace std;

int arr[11] = {4, 5, 1, 1, 5, 4, -3, -13, 9, 20, 13};

int getSum(int idx)
{
    int sum = 0;

    for (int i = idx; i < idx + 5; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int sum = getSum(0);
    int max = sum;
    int maxIndex = 0;

    for (int i = 0; i <= 11 - 5; i++)
    {
        if (sum > max)
        {
            max = sum;
            maxIndex = i;
        }

        // 범위를 넘어가면 다음 거 못하게 막음
        if (i == 11 - 5)
            break;

        // 다음 것 미리 준비
        sum -= arr[i];
        sum += arr[i + 5];
    }

    cout << maxIndex;

    return 0;
}
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
    int max = 0;
    int maxIndex;
    for (int i = 0; i <= 6; i++)
    {
        int ret = getSum(i);
        if (ret > max)
        {
            max = ret;
            maxIndex = i;
        }
    }

    cout << maxIndex;

    return 0;
}
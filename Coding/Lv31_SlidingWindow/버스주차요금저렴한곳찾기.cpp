#include <iostream>
using namespace std;

int arr[9] = {1, 2, 3, 3, 5, 1, 0, 1, 3};
int minSum = 21e8;

int main()
{
    int n;
    cin >> n;

    int sum;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    for (int i = 0; i <= 9 - n; i++)
    {
        if (sum < minSum)
        {
            minSum = sum;
        }

        if (i == 9 - n)
            break;

        sum -= arr[i];
        sum += arr[i + n];
    }

    cout << minSum;

    return 0;
}

/* 또 다른 코드
#include <iostream>
using namespace std;

int n;

int getSum(int idx)
{
    int sum = 0;
    for (int i = idx; i < idx + n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    cin >> n;

    int sum = getSum(0);
    int min = sum;

    int limit = 9 - n;
    for (int i = 0; i <= limit; i++)
    {
        if (sum < min)
        {
            min = sum;
        }

        if (i == limit)
            break;

        sum -= arr[i];
        sum += arr[i + n];
    }

    cout << min;

    return 0;
}
*/
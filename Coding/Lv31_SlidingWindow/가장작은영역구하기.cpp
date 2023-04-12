#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[10];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum = arr[0] + arr[1] + arr[2] + arr[3];
    int min = 21e8;

    for (int i = 0; i <= n - 4; i++)
    {
        if (sum < min)
        {
            min = sum;
        }

        if (i == n - 4)
            break;

        sum -= arr[i];
        sum += arr[i + 4];
    }

    cout << min;

    return 0;
}

/* 또 다른 코드
#include <iostream>
using namespace std;

int n;
int arr[10] = {0};

int getSum(int idx)
{
    int sum = 0;

    for (int i = idx; i < idx + 4; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum = getSum(0);
    int min = 99;

    int limit = n - 4;
    for (int i = 0; i <= limit; i++)
    {
        if (sum < min)
        {
            min = sum;
        }

        if (i == limit)
            break;

        sum -= arr[i];
        sum += arr[i + 4];
    }

    cout << min;

    return 0;
}
*/
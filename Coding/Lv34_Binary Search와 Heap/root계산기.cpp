#include <iostream>
#include <string>
using namespace std;

int bs(int start, int end, int tar)
{
    int max = 0;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        int n = mid * mid;

        if (n == tar)
            return mid;

        if (n > tar)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
            if (mid > max)
                max = mid;
        }
    }

    return max;
}

int main()
{
    int n;
    cin >> n;
    cout << bs(0, n, n);
    return 0;
}

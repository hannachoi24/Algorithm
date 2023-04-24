#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bs(int start, int end, int target)
{
    int max = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int n = mid * mid;

        if (n == target)
            return mid;

        if (n > target)
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
    int ret = bs(1, 20, 20);
    cout << ret; // 4
    return 0;
}
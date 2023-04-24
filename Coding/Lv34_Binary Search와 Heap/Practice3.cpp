#include <iostream>
using namespace std;

int arr[8] = {-6, 1, 2, 5, 6, 7, 9, 15};

int bs(int start, int end, int target)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    cout << bs(0, 7, 6);

    return 0;
}
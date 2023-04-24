#include <iostream>
using namespace std;

// Binary Search

int target = 31;

int main()
{
    int start = 1;
    int end = 50;
    int mid = 0;

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (mid == target)
        {
            cout << "찾았습니다.";
            break;
        }
        if (mid > target)
            end = mid - 1;
        else
        {
            start = mid + 1;
        }
    }

    cout << mid;

    return 0;
}
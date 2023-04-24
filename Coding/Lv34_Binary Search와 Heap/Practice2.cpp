#include <iostream>
using namespace std;

int arr[8] = {-6, 1, 2, 5, 6, 7, 9, 15};
int target;

int bs(int start, int end)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == target)
        {
            return 1;
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
    return 0;
}

int main()
{
    target = 6;
    int ret = bs(0, 7);

    if (ret)
        cout << "O";
    else
        cout << "X";

    return 0;
}
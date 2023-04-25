#include <iostream>
using namespace std;

int arr[10] = {4, 4, 5, 7, 8, 10, 20, 22, 23, 24};
int target;

int bs(int start, int end)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == target)
            return 1;

        if (arr[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return 0;
}

int main()
{
    cin >> target;

    if (bs(0, 9))
    {
        cout << "O";
    }
    else
        cout << "X";

    return 0;
}
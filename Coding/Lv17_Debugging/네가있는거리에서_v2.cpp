#include <iostream>

using namespace std;

int findIndex(int arr[], int idx, int target)
{
    for (int i = idx; i < 8; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[8] = {5, 9, 4, 6, 1, 5, 8, 9};

    int idx, target, offset;
    cin >> idx >> target;

    offset = findIndex(arr, idx, target) - idx;

    cout << offset;

    return 0;
}
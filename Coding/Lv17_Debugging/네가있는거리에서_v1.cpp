#include <iostream>
using namespace std;

int main()
{
    int arr[8] = {5, 9, 4, 6, 1, 5, 8, 9};
    int idx, offset;
    int target, target_idx;
    int i;

    cin >> idx >> target;

    for (i = 0; i < 8; i++)
    {
        if (arr[i] == target)
        {
            target_idx = i;
            break;
        }
    }

    offset = target_idx - idx;

    cout << offset;

    return 0;
}
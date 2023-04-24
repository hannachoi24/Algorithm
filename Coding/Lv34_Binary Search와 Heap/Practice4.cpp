#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;

int bs(int start, int end, int target)
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
    freopen_s(new FILE *, "input.txt", "r", stdin);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int tar;
        cin >> tar;
        if (bs(0, arr.size() - 1, tar))
            cout << "O";
        else
            cout << "X";
    }

    return 0;
}
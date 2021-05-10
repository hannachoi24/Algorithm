#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int target, int start, int end)
{
    if (start > end) // start, end -> 인덱스 값
        return -1;
    int mid = (start + end) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return binarySearch(arr, target, start, mid - 1);
    else
        return binarySearch(arr, target, mid + 1, end);
}

int n, target;
vector<int> arr;

int main(void)
{
    cin >> n >> target;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int result = binarySearch(arr, target, 0, n - 1);
    if (result == -1)
    {
        cout << "원소가 존재하지 않습니다." << '\n';
    }
    else
    {
        cout << result + 1 << '\n';
    }
}
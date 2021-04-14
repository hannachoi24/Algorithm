#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    int target = 1;

    for (int i = 0; i < n; i++)
    {
        if (target < arr[i]) // 만들 수 없는 금액을 찾았을 때 반복 종료
            break;
        target += arr[i];
    }
    cout << target << '\n';
}
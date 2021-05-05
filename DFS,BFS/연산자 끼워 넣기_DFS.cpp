#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr;
int add, sub, mul, divi;

int minValue = 1e9;
int maxValue = -1e9;

void dfs(int i, int now)
{
    if (i == n)
    {
        minValue = min(minValue, now);
        maxValue = max(maxValue, now);
    }
    else
    {
        if (add > 0)
        {
            add -= 1;
            dfs(i + 1, now + arr[i]);
            add += 1;
        }
        if (sub > 0)
        {
            sub -= 1;
            dfs(i + 1, now - arr[i]);
            sub += 1;
        }
        if (mul > 0)
        {
            mul -= 1;
            dfs(i + 1, now * arr[i]);
            mul += 1;
        }
        if (divi > 0)
        {
            divi -= 1;
            dfs(i + 1, now / arr[i]);
            divi += 1;
        }
    }
}

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cin >> add >> sub >> mul >> divi;
    dfs(1, arr[0]);
    cout << maxValue << '\n';
    cout << minValue << '\n';
}

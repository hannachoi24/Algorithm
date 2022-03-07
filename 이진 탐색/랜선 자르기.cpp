#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> k >> n;

    vector<ll> kRope;
    ll rope;

    for (int i = 0; i < k; i++)
    {
        cin >> rope;
        kRope.push_back(rope);
    }

    sort(kRope.begin(), kRope.end());

    ll result = -21e8;
    ll start = 1;
    ll end = kRope.back();

    while (start <= end)
    {
        ll mid = (start + end) / 2;

        int sum = 0;
        for (ll num : kRope)
        {
            sum += (num / mid); // 개수는 k개의 랜선을 402로 나눈 몫을 더해서 구한다.
        }

        if (sum >= n) // 개수가 n이상이면 답이 될 수 있도록 result를 갱신
        {
            if (result < mid)
                result = mid;
            start = mid + 1;
        }

        else // mid로 자른 랜선들의 개수가 n개 미만이면, 랜선의 길이를 다시 반절로 줄인다.
        {
            end = mid - 1;
        }
    }
    cout << result;

    return 0;
}
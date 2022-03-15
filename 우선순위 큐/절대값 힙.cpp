#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

// <data type, container type, 정렬 기준>
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 절대값, 원본값

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> ans;
    int n, x;
    cin >> n;

    while (n--)
    {
        cin >> x;

        if (x != 0)
        {
            pq.push({abs(x), x});
        }
        else
        {
            if (!pq.empty())
            {
                ans.push_back(pq.top().second);
                pq.pop();
            }
            else
            {
                ans.push_back(0);
            }
        }
    }
    for (int x : ans)
    {
        cout << x << '\n';
    }

    return 0;
}
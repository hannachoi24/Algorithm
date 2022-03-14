#include <iostream>
#include <queue>
using namespace std;

/* priority_queue가 최대 힙(내림차순)이므로 오름차순으로 표현해주면 최소 힙이 될 것이다.*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int> pq;
    int n;

    cin >> n;

    while (n--)
    {
        int x;
        cin >> x;

        if (x == 0)
        {
            if (pq.empty())
            {
                cout << "0\n";
                continue;
            }
            else
            {
                cout << -pq.top() << '\n';
                pq.pop();
            }
        }
        else
        {
            pq.push(-x);
        }
    }
    return 0;
}
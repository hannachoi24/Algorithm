#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> minq;

int main()
{
    minq.push(6);
    minq.push(3);
    minq.push(2);
    minq.push(6);
    minq.push(8);

    while (!minq.empty())
    {
        cout << minq.top();
        minq.pop();
    }

    return 0;
}
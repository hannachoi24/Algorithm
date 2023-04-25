#include <iostream>
#include <queue>
using namespace std;

// Priority Queue
// 1. Max Heap
// 2. Min Heap
// 3. 다중 조건 Heap

priority_queue<int> maxq;
priority_queue<int, vector<int>, greater<int>> minq;

int main()
{
    q.push(2);
    q.push(3);
    q.push(1);
    q.push(7);

    while (!q.empty()) // 힙소트
    {
        cout << q.top(); // O(logN)
        q.pop();
    }

    // O(NlogN)

    return 0;
}
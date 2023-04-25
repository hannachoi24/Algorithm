#include <iostream>
#include <queue>
using namespace std;

// Priority Queue

priority_queue<int> q;

int main()
{
    q.push(2);
    q.push(3);
    q.push(1);
    q.push(7);

    cout << q.top();
    q.pop();

    cout << q.top();

    return 0;
}
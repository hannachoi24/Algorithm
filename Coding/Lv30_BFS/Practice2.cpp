#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int main()
{
    q.push(1);
    q.push(2);
    q.push(5);
    q.push(7);

    while (!q.empty())
    {
        cout << q.front();
        q.pop();
    }

    return 0;
}
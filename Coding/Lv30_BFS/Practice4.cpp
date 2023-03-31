#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int main()
{
    q.push(5);
    q.push(4);
    q.push(3);

    for (int i = 0; i < 5; i++)
    {
        q.pop();
        int result = (q.front() * 55 + 17) % 11;
        q.push(result);
    }

    while (!q.empty())
    {
        cout << q.front();
        q.pop();
    }

    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    char ch;
    int n;
};

queue<Node> q;

int main()
{
    q.push({'A', 9});
    q.push({'B', 7});
    q.push({'Q', 5});
    q.push({'T', 4});

    while (!q.empty())
    {
        Node ret = q.front();
        cout << ret.ch << " " << ret.n << '\n';
        q.pop();
    }

    return 0;
}
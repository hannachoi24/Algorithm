#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int n;
    char ch;
};

priority_queue<Node> q;

bool operator<(Node a, Node b)
{
    if (a.n > b.n)
        return 1;
    if (a.n < b.n)
        return 0;
    return a.ch < b.ch;
}

int main()
{
    int n;
    cin >> n;

    q.push({9, 'A'});
    q.push({8, 'B'});
    q.push({9, 'A'});
    q.push({10, 'C'});
    q.push({15, 'A'});

    for (int i = 0; i < n; i++)
    {
        Node ret = q.top();
        q.pop();

        cout << ret.n << "(" << ret.ch << ")\n";

        ret.n = ret.n * 2 % 17;

        q.push(ret);
    }

    return 0;
}
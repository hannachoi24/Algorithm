#include <iostream>
#include <queue>
using namespace std;

// 우선순위
// 문자 작은 것
// 수 큰 것

struct Node
{
    int n;
    char ch;
};

bool operator<(Node a, Node b)
{
    if (a.ch > b.ch)
        return 1;
    if (a.ch < b.ch)
        return 0;
    return a.n < b.n;
}

priority_queue<Node> q;

int main()
{
    q.push({'A', 7});
    q.push({'C', 9});
    q.push({'C', 7});
    q.push({'D', 6});
    q.push({'A', 5});

    while (!q.empty())
    {
        Node ret = q.top();
        cout << ret.ch << " " << ret.n << '\n';
        q.pop();
    }

    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

// 우선순위 조건
// 1. 짝수 우선
// 2. 작은수 우선

// 연산자 오버로딩(암기) -> 다중 조건일때 사용

struct Node
{
    int n;
};

// 암기
bool operator<(Node a, Node b)
{
    if (b.n % 2 == 0 && a.n % 2 == 1)
        return 1;
    if (b.n % 2 == 1 && a.n % 2 == 0)
        return 0;
    return b.n < a.n;
}

priority_queue<Node> q;

int main()
{
    q.push({3});
    q.push({6});
    q.push({1});
    q.push({3});
    q.push({5});
    q.push({2});
    q.push({4});

    while (!q.empty())
    {
        cout << q.top().n;
        q.pop();
    }

    return 0;
}

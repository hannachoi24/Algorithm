#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Node
{
    int n;
    char ch;
};

Node buf[] = {{3, 'A'}, {4, 'C'}, {9, 'D'}, {9, 'H'}, {9, 'A'}};

int cmp(Node a, Node b)
{
    // 수 큰 거 우선순위 높음 (내림 차순)
    if (a.n > b.n)
        return 1;
    if (a.n < b.n)
        return 0;

    // 문자 작은 거 우선순위 높음
    return a.ch < b.ch;
}

int main()
{
    // 다중조건
    sort(buf, buf + 5, cmp);

    return 0;
}
#include <iostream>
using namespace std;

struct Node
{
    int n;
    char a;
};

int main()
{
    Node t = {3, 'A'};

    Node *p = &t;

    // 화살표는 구조체 변수를 가리키는 포인터에서만 가능(가리키는 곳 안에 것)
    cout << p->n; // (*p).a와 같음
    cout << p->a;

    return 0;
}
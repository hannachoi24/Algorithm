#include <iostream>
using namespace std;

struct Node
{
    int x;
    Node *p;
};

int main()
{
    Node a, b, c;
    a.p = &b;
    b.p = &c;

    a.x = 11;
    a.x = 22;
    a.x = 33;

    return 0;
}
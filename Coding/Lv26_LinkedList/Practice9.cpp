#include <iostream>
using namespace std;

struct Node
{
    int x;
    Node *p;
};

int main()
{
    Node a, b;
    a.x = 3;
    b.x = 7;

    a.p = &b;
    b.p = NULL;

    return 0;
}
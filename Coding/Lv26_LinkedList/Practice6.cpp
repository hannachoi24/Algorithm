#include <iostream>
using namespace std;

struct Node
{
    int n;
    char a, b;
};

int main()
{
    Node a = {3, 'Q', 'H'};
    Node *t = &a;
    Node *q = &a;

    cout << t->n + q->n;

    return 0;
}
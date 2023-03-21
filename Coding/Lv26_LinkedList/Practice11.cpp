#include <iostream>
using namespace std;

struct Node
{
    char ch;
    Node *p;
};

int main()
{
    Node a, b, c;
    Node *head;

    a.ch = '3';
    b.ch = '9';
    c.ch = 'Z';

    t = &a;
    a.p = &b;   // t->p = &b와 같음
    b.p = &c;   // t->p->p = &c와 같음
    c.p = NULL; // t->p->p->p = NULL

    return 0;
}
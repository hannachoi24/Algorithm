#include <iostream>
using namespace std;

struct Node
{
    int a;
    int *p;
    char *g;
};

int t = 3;
char ch = 'A';
Node f;

int main()
{
    f.a = 3;
    f.p = &t;
    f.g = &ch;

    return 0;
}
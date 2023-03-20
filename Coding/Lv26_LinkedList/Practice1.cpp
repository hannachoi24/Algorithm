#include <iostream>
using namespace std;

struct Node
{
    int a;
    int b;
};

int main()
{
    KFC da = {1, 2};
    KFC db = {3, 4};

    cout << da.a;
    cout << da.b;
    cout << db.c;
    cout << db.d;

    return 0;
}
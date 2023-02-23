#include <iostream>
using namespace std;

/*더블포인터(가리키고 있는 싱글포인터의 값) 연습*/

int main()
{
    int t = 7;
    int *kg = &t;
    int **p = &kg;
    int **b = &kg;

    int a = 9;
    int *g = &a;
    int *r = &a;

    cout << *kg << "=";
    cout << **p << "\n";

    cout << g << "=";
    cout << r << "\n";

    cout << *p << "=";
    cout << kg << "\n";

    return 0;
}
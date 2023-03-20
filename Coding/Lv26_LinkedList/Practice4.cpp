#include <iostream>
using namespace std;
// 포인터
// 1. 포인터변수는 주소를 저장한다.
// 2. 주소를 저장할 때, 가리킨다고 표현

int main()
{
    char dg = 'b';

    char *a = &dg;
    char *c = &dg;

    cout << *a;
    cout << *c * 2;

    return 0;
}
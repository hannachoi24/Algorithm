#include <iostream>
using namespace std;

/*포인터 연습*/
// 포인터는 주소를 저장하고 있는 변수
// 저장하고 있을 때 가리킨다

int main()
{
    int a;
    int *v = &a;

    *v = 100;

    return 0;
}
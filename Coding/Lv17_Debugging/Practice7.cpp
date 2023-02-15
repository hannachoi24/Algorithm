#include <iostream>
using namespace std;

// 빌드 에러
// 컴파일 에러
// 링커 에러
// 런타임 에러(빌드는 됨)

void abc()
{
    int buf[10] = {23};
    buf[-1] = 1;
}

int main()
{
    abc();

    return 0;
}
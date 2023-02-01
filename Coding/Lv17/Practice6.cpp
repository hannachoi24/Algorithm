#include <iostream>
using namespace std;

// 호출 스택, 지역 변수 창으로 확인해보는 연습

int t = 1403;

void kfc()
{
    int a = 10;
    int b = 999;
}

int main()
{
    int a = 10;
    int b = 20;
    t++;

    kfc();

    return 0;
}
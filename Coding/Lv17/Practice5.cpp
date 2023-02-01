#include <iostream>
using namespace std;

// 호출 스택 창으로 확인해보는 연습

void abc();
void kfc();
void cdd();
void bfs();

void bts()
{
    cout << "HI";
}

void abc()
{
    kfc();
    cdd();
    cout << "abc";
}

void kfc()
{
    cdd();
    bts();
}

void cdd()
{
    bts();
    cout << "cdd";
}

int main()
{
    abc();
    cdd();

    return 0;
}
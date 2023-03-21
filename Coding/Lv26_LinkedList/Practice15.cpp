#include <iostream>
using namespace std;

// 힙-메모리공간(원하는 변수 만큼 공간 할당하기 위해)

struct Node
{
    int x;
    Node *p;
};

int main()
{
    Node *head;
    head = new Node(); // 괄호를 붙이면 0으로 초기화

    head->x = 3;
    head->p = new Node();
    head->p->x = 7;
    head->p->p = new Node();
    head->p->p->x = 9;
    head->p->p->p = NULL;

    return 0;
}
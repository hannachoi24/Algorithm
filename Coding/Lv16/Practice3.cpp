#include <iostream>

using namespace std;

// VS는 Trace시작할 때 F10: 시작(Step Over), Shift + F5: 끔, Ctrl + F10: 점프, F11: Step Into
// 다른 IDE들은 BreakPoint걸고 F5눌러서 Trace 시작
// Trace: 한줄씩 실행하는 기능
// Debugging: 버그죽이는 활동하고 있는 것
// 디버깅을 할 때 Trace라는 기능으로 디버깅

void abc()
{
    cout << "HI";
}

int main()
{
    int a = 10;
    int b = 20;
    int c = 30;
    abc();      // 여기까지 점프 후 Step Into
    int d = 40; // 요기
    int e = 50;
    a = 20;
    b = 30;
    c = 40;
    abc();  // Over
    d = 50; // 점프 시작
    a = 35;
    a = 67;
    abc();  // 점프 도착 후 Into
    b = 24; // 요기
    a = 50;
    c = 356;

    return 0;
}
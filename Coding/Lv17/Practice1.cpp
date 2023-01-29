#include <iostream>

using namespace std;

// void abc()
// {
//     cout << "!";
// }

void abc(int arr[50])
{

    for (int i = 1; i < 50; i++)
    {
        // 42번 index부터 뭔가 값이 이상함 -> 디버깅 코드 삽입(쓰레기 값)
        // ex) if (i == 42) {int d = 1;}
        if (i == 42)
        {
            int d = 1;
        }
        arr[i] = (arr[i - 1] * 7 + 41) % 11;
    }
}
int main()
{
    // 한줄 삭제 Shift + Del
    // 한줄 복제 Ctrl + D
    // trace 종료 (Shift + F5)
    // cout << "#";
    // cout << "#";
    // cout << "#";
    // cout << "#";
    // cout << "#";
    // cout << "#";
    // cout << "#";
    // cout << "#";

    // abc(); // over
    // abc(); // into
    // abc(); // over
    // abc(); // into
    // abc(); // over
    // abc(); // trace 종료 (Shift + F5)

    // int a = 10;
    // a = 20;
    // a = 30;
    // int b = 20;
    // b = 30;
    // b = 40;
    // int sum = a + b;

    // 조사식 포거스 -> Ctrl + Alt + W 눌렀다가 손 떼고 숫자 1 누르기
    // 포커스가 조사식에서 에디터로 돌아가기 -> ESC

    // int j = 0;
    // for (int i = 0; i < 10; i++)
    // {
    //     j++; // i가 3일 때, j값 확인하기
    // }

    // int k = 0;
    // for (int i = 0; i < 10; i++)
    // {
    //     k++;
    //     k++;
    //     k++; // k가 6일 때 k값 확인하기
    // }

    int arr[50] = {5};
    abc(arr);

    return 0;
}
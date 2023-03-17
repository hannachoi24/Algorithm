#include <iostream>
#include <string>
using namespace std;

// 문자열 내에서 ABC가 총 몇개인지

int main()
{
    string str = "ABCAAABCAAABCA";

    int a = -1; // a + 1부터 찾기 때문
    // int a = 0
    int cnt = 0;

    // ABC가 몇개가 나올지 모르니 while 무한루프 돌리기
    while (1)
    {
        a = str.find("ABC", a + 1);
        // b = str.find("ABC", a);
        if (a == -1)
            break;

        cnt++;
        // a = b + 1;
    }

    cout << cnt;

    return 0;
}
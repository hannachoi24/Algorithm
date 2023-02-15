#include <iostream>

using namespace std;

/* 끝 문자와 중간 문자 바꾸고 역순 출력하기 */

int main()
{

    char str[10];
    cin >> str;

    // 1.문자열 길이
    int len = 0;
    for (int i = 0; i < 10; i++)
    {
        if (str[i] == '\0')
        {
            len = i;
            break;
        }
    }

    // 2.에러처리
    if (len % 2 == 0)
    {
        cout << "ERROR\n";
        return 0;
    }

    // 3.세팅
    int last = len - 1;
    int mid = len / 2;

    // 4.SWAP
    int temp = str[last];
    str[last] = str[mid];
    str[mid] = temp;

    // 5.역순 출력
    for (int i = len - 1; i >= 0; i--)
    {
        cout << str[i];
    }

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

// 주어진 문장에서 찾을 문자의 개수 출력

int main()
{
    string str = "ABCDAGDISSJKFCKFCKFC";
    string tar;
    cin >> tar;

    int a = -1;
    int cnt = 0;
    while (1)
    {
        a = str.find(tar, a + 1);
        if (a == -1)
            break;
        cnt++;
    }

    cout << cnt;

    return 0;
}
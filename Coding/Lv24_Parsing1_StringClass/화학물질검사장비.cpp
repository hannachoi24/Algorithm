#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    cin >> str;

    int a = -1;
    int b = -1;
    int passCnt = 0;
    int failCnt = 0;

    // 입력받은 문자열과 찾아야 할 문자열 모두 대문자로 변경하여 비교
    transform(str.begin(), str.end(), str.begin(), ::toupper);

    while (1)
    {
        a = str.find("PASS", a + 1);
        if (a == -1)
            break;
        passCnt++;
    }

    while (1)
    {
        b = str.find("FAIL", b + 1);
        if (b == -1)
            break;
        failCnt++;
    }

    int sum = passCnt + failCnt;
    int result = (double)passCnt / sum * 100; // 소수점 이하를 모두 버림
    cout << result << "%";

    return 0;
}

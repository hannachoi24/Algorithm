#include <iostream>
#include <cstring>
using namespace std;

// 문자열 라이브러리 연습

int main()
{
    char id[10];
    char password[10];

    cin >> id >> password;

    if (!strcmp(id, "BBQ") && !strcmp(password, "1234"))
    {
        cout << "PASS";
    }
    else
        cout << "FAIL";

    return 0;
}
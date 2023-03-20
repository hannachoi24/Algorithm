#include <iostream>
#include <string>
using namespace std;

// replace
// KFC -> *** 바꿔주는 프로그램

int main()
{
    string str = "ABKFC__KFC";

    int a = -1;
    while (1)
    {
        a = str.find("KFC", a + 1);
        if (a == -1)
            break;
        str.erase(a, 3);
        str.insert(a, "***");
    }

    cout << str;

    return 0;
}
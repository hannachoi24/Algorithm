#include <iostream>
#include <string>
using namespace std;

// 문자열 내에서 GOLD가 총 몇개인지

int getCount(string s)
{
    int cnt = 0;
    int a = -1;
    while (1)
    {
        a = s.find("GOLD", a + 1);
        if (a == -1)
            break;

        cnt++;
    }

    return cnt;
}

int main()
{
    string str[4] = {
        "GOLDABGOLD",
        "GOLDTTTT",
        "AGOLDGOLD",
        "GOLDTTTT"};

    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        cnt += getCount(str[i]);
    }
    cout << cnt;

    return 0;
}
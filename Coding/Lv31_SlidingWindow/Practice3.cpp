#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "ABABTABCABABAACD";
    string tar = "ABA";
    string s = str.substr(0, 3);
    int cnt = 0;

    int limit = str.length() - tar.length();
    for (int i = 0; i <= limit; i++)
    {
        if (s == tar)
        {
            cnt++;
        }

        // 범위를 넘어가면 다음 거 못하게 막음
        if (i == limit)
            break;

        s.erase(s.begin());
        s += str[i + tar.length()];
    }

    cout << cnt;

    return 0;
}
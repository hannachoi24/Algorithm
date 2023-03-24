#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;

    cin >> str;

    int hash[200] = {0};

    for (int i = 0; i < str.length(); i++)
    {
        hash[str[i]]++;
    }

    int cnt = 0;
    for (int i = 0; i < 200; i++)
    {
        if (hash[i])
        {
            cnt++;
        }
    }

    cout << cnt << "종류";

    return 0;
}
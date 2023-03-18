#include <iostream>
#include <string>
using namespace std;

int getCount(string str)
{
    int cnt = 0;
    int a = -1;

    while (1)
    {
        a = str.find("MCD", a + 1);
        if (a == -1)
            break;

        cnt++;
    }

    return cnt;
}

int main()
{
    string input[5];

    int cnt = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> input[i];
        cnt += getCount(input[i]);
    }

    cout << cnt;

    return 0;
}
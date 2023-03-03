#include <iostream>
#include <string>
using namespace std;

void run(int len)
{
    cout << len << " ";
    if (len == 1)
    {
        return;
    }

    run(len - 1);
    cout << len << " ";
}

int main()
{
    string str;
    cin >> str;

    int len = str.length();

    run(len);

    return 0;
}
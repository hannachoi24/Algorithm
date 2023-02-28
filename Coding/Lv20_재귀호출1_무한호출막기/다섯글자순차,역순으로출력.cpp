#include <iostream>
#include <string>
using namespace std;

string str = "";

void run(int idx)
{
    if (idx == 5)
    {
        cout << '\n';
        return;
    }

    cout << str[idx];
    run(idx + 1);
    cout << str[idx];
}

int main()
{
    cin >> str;

    run(0);
    return 0;
}
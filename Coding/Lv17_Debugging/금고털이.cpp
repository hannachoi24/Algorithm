#include <iostream>
using namespace std;

int password[4] = {3, 7, 4, 9};
int input[4];

int isSame()
{
    for (int i = 0; i < 4; i++)
    {
        if (password[i] != input[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        cin >> input[i];
    }

    if (isSame())
    {
        cout << "pass";
    }
    else
    {
        cout << "fail";
    }

    return 0;
}
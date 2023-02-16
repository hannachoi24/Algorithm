#include <iostream>
#include <cstring>
using namespace std;

char arr[10];
char tar[6] = "GHOST";

int isSame(int idx)
{
    for (int i = 0; i < 5; i++)
    {
        if (tar[i] != arr[idx + i])
            return 0;
    }

    return 1;
}

int main()
{

    cin >> arr;

    if (isSame(1))
    {
        cout << "존재";
    }
    else
        cout << "존재하지 않음";

    return 0;
}
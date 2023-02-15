#include <iostream>
#include <string>
using namespace std;

char arr[2][6] = {
    'A', '7', '9', 'T', 'K', 'Q',
    'M', 'I', 'N', 'C', 'O', 'D'};

char a, b;

void isExist()
{
    bool flagA = false;
    bool flagB = false;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (arr[i][j] == a)
            {
                flagA = true;
            }

            if (arr[i][j] == b)
            {
                flagB = true;
            }
        }
    }

    if (flagA)
    {
        cout << a << " : 존재" << '\n';
    }
    else
        cout << a << " : 없음" << '\n';

    if (flagB)
    {
        cout << b << " : 존재" << '\n';
    }
    else
        cout << b << " : 없음" << '\n';
}

int main()
{

    cin >> a >> b;
    isExist();

    return 0;
}
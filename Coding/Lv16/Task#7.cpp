#include <iostream>
#include <string>
using namespace std;

char arr[3][10] = {0};

int isExist(char ch)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] == ch)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }

    if (isExist('M'))
    {
        cout << "M이 존재합니다";
    }

    else
        cout << "M이 존재하지 않습니다";

    return 0;
}
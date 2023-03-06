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

/* 또 다른 코드
#include <iostream>
using namespace std;

int isExist(char arr[2][7], char input)
{
    int x, y;

    for (y = 0; y < 2; y++)
    {
        for (x = 0; x < 6; x++)
        {
            if (arr[y][x] == input)
            {
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    char arr[2][7] =
    {
        "A79TKQ",
        "MINCOD",
    };

    char input1, input2;
    int result1, result2;

    cin >> input1 >> input2;

    result1 = isExist(arr, input1);
    result2 = isExist(arr, input2);

    if (result1 == 1)
    {
        cout << input1 << " : 존재" << endl;
    }
    else
    {
        cout << input1 << " : 없음" << endl;

    }

    if (result2 == 1)
    {
        cout << input2 << " : 존재" << endl;
    }
    else
    {
        cout << input2 << " : 없음" << endl;
    }

    return 0;
}
*/
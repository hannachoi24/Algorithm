#include <iostream>
using namespace std;

int main()
{
    char arr[3][4] = {'A', 'T', 'K', 'B',
                      'C', 'Z', 'F', 'D',
                      'H', 'G', 'E', 'I'};

    char ch;
    int a, b;
    cin >> ch >> a >> b;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == ch)
            {
                cout << arr[i + a][j + b];
            }
        }
    }

    return 0;
}
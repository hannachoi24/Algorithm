#include <iostream>
using namespace std;

// for문으로 1~9자리 비번 출력

int main()
{
    for (int a = 1; a <= 9; a++)
    {
        for (int b = 1; b <= 9; b++)
        {
            for (int c = 1; c <= 9; c++)
            {
                for (int d = 1; d <= 9; d++)
                {
                    cout << a << b << c << d << '\n';
                }
            }
        }
    }

    return 0;
}